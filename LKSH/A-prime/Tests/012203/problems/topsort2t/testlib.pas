{ Copyright(c) SPb-IFMO CTD Developers, 2000 }
{ Copyright(c) Anton Sukhanov, 1996 }

{ $Id: testlib.pas,v 2.0.fpc 2001/11/08 15:37:55 sta Exp $ }

{ Evaluating programs support stuff }

{$ifdef VER70}
{$ERROR}
{$ELSE}
{$I-,O+,Q-,R-,S-}
{$endif}

(*
    Program, using testlib running format:
      CHECK <Input_File> <Output_File> <Answer_File> [<Result_File> [-appes]],

    If result file is specified it will contain results.
*)

(*
    Modifications log:
      dd.mm.yyyy  modified by          modification log
      27.10.2002  Andrew Stankevich    Buffered input (speedup up to 2 times on big files)
                                       BP7.0 compatibility removed
      17.09.2000  Andrew Stankevich    XML correct comments
      01.08.2000  Andrew Stankevich    Messages translated to English
                                       APPES support added   
                                       FAIL name changed
      07.02.1998  Roman Elizarov       Correct EOF processing
      12.02.1998  Roman Elizarov       SeekEoln corrected
                                       eoln added
                                       nextLine added
                                       nextChar is now function
*)

unit testlib;

interface

const 
    eofChar  = #$1A;
    eofRemap = ' ';
    NumberBefore = [#10,#13,' ',#09];
    NumberAfter  = [#10,#13,' ',#09,eofChar];
    lineAfter    = [#10,#13,eofChar];
    Blanks       = [#10,#13,' ',#09];
    eolnChar     = [#10,#13,eofChar];

    BUFFER_SIZE = 1048576;

type 
    CharSet = set of char;
    TMode   = (_Input, _Output, _Answer);
    TResult = (_ok, _wa, _pe,  _fail, _dirt);
              { 
                _ok - accepted, 
                _wa - wrong answer, 
                _pe - output format mismatch,
                _fail - when everything fucks up 
                _dirt - for inner using
              }

    InStream = object
        f: file; { file }
        name: string; { file name }
        mode: TMode;
        opened: boolean;
        fpos: integer;
        size: integer;

        buffer: array [0..BUFFER_SIZE - 1] of char;
        bpos: integer;
        bsize: integer;

        { for internal usage }
        procedure fillbuffer;
        constructor init(fname: string; m: TMode);

        function curchar: char; { returns cur }
        procedure skipchar;  { skips current char }
        function nextchar: char;  { moves to next char }

        procedure Reset;

        function Eof: boolean;
        function SeekEof: boolean;

        function Eoln: boolean;
        function SeekEoln: boolean;

        procedure NextLine; { skips current line }

        { Skips chars from given set }
        { Does not generate errors }
        procedure Skip(setof: CharSet);

        { Read word. Skip before all chars from `before`
          and after all chars from `after`. }
        function ReadWord(Before, After: CharSet): string;

        { reads integer }
        { _pe if error }
        function ReadLongint: integer;

        { = readlongint }
        function ReadInteger: integer;

        { reads real }
        { _pe if error }
        function ReadReal: extended;

        { same as readword([], [#13 #10]) }
        function ReadString: string;

        { for internal usage }
        procedure Quit(res: TResult; msg: string);
        procedure Close;

    end;


procedure Quit(res: TResult; msg: string);

var 
    inf, ouf, ans: InStream;
    ResultName: string; { result file name }
    AppesMode: boolean;

implementation

uses 
    sysutils;


const
    LightGray = $07;    
    LightRed  = $0c;    
    LightCyan = $0b;    
    LightGreen = $0a;

procedure TextColor(x: word);
{var
    h: THandle;}
begin
{    h := GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);}
end;

const 
    outcomes: array[TResult] of string = (
        'accepted',
        'wrong-answer',
        'presentation-error',
        'fail',
        'fail'
    );

procedure XMLSafeWrite(var t: text; s: string);
var
    i: integer;
begin
    for i := 1 to length(s) do
    begin
        case s[i] of
            '&': write(t, '&amp;');
            '<': write(t, '&lt;');
            '>': write(t, '&gt;');
            '"': write(t, '&quot;');
            #128..#255: write(t, '?');
            #0..#31: write(t, '.');
            else
                write(t, s[i]);
        end; { case }
    end;
end;

procedure Quit(res: TResult; msg: string);
var 
    resfile: text;
    errorname: string;

    procedure scr(color: word; msg: string);
    begin
       if resultname = '' then { if no result file }
       begin
          TextColor(color); write(msg); TextColor(LightGray);
       end;
    end;

begin
    if (res = _ok)and(ouf.opened) then
    begin
        if not ouf.seekeof then quit(_dirt, 'Extra information in the output file');
    end;

    case res of
        _fail: 
            begin 
{                beep(100, 300);}
                ErrorName := 'FAIL ';
                Scr(LightRed, ErrorName);
            end;

        _dirt: 
            begin
                ErrorName := 'wrong output format ';
                Scr(LightCyan, ErrorName);
                res := _pe;
            end;

        _pe: 
            begin
                ErrorName := 'wrong output format ';
                Scr(LightRed, ErrorName);
            end;

        _ok: 
            begin
                ErrorName := 'ok ';
                Scr(LightGreen, ErrorName);
            end;

        _wa: 
            begin
                ErrorName := 'wrong answer ';
                scr(LightRed, ErrorName);
            end;

        else 
            Quit(_fail, 'What is the code ??? ');
    end;

    if ResultName <> '' then
    begin
        assign(RESFILE, ResultName); { Create file with result of evaluation }
        rewrite(ResFile);
        if IOResult <> 0 then Quit(_fail, 'Can not write to Result file');
        if AppesMode then
        begin
            write(ResFile, '<result outcome = "', outcomes[res], '">');
            xmlsafewrite(ResFile, msg);
            writeln(ResFile, '</result>');
        end else  begin
            writeln(ResFile, '.Testlib Result Number = ', ord(res));
            writeln(ResFile, '.Result name (optional) = ', ErrorName);
            writeln(ResFile, '.Check Comments = ', msg);
        end;
        close(ResFile);
        if IOResult <> 0 then Quit(_fail, 'Can not write to Result file');
    end;

    Scr(LightGray, msg);
    writeln;

    if Res = _fail then HALT(1);

    close(inf.f); 
    if ouf.opened then close(ouf.f); 
    close(ans.f);

    TextColor(LightGray);

    if (res = _ok) or (ResultName <> '') then 
        halt(0)
    else 
        halt(5);
end;

procedure InStream.fillbuffer;
var
    left: integer;
begin
    left := size - fpos;
    bpos := 0;

    if left = 0 then
    begin
        bsize := 1;
        buffer[0] := eofchar;
    end else begin
        blockread(f, buffer, buffer_size, bsize);
        fpos := fpos + bsize;
    end;
end;

procedure InStream.Reset;
begin
    if opened then
        close;

    fpos := 0;
    system.reset(f, 1);

    size := filesize(f);

    if ioresult <> 0 then
    begin
        if mode = _output then
            quit(_pe, 'File not found: "' + name + '"');
        bsize := 1;
        bpos := 0;
        buffer[0] := eofchar;
    end else begin
        fillbuffer;
    end;

    opened := true;
end;

constructor InStream.init(fname: string; m: TMode);
begin
    opened := false;
    name := fname;
    mode := m;

    assign(f, fname);

    reset;
end;

function InStream.Curchar: char;
begin
    curchar := buffer[bpos];
end;

function InStream.NextChar: char;
begin
    NextChar := buffer[bpos];
    skipchar;
end;

procedure InStream.skipchar;
begin
    if buffer[bpos] <> EofChar then 
    begin
        inc(bpos);
        if bpos = bsize then
            fillbuffer;
    end;
end;

procedure InStream.Quit(res: TResult; msg: string);
begin
    if mode = _Output then 
        testlib.quit(res, msg)
    else 
        testlib.quit(_fail, msg + ' (' + name + ')');
end;

function InStream.ReadWord(Before, After: CharSet): string;
begin
    while buffer[bpos] in Before do skipchar;

    if (buffer[bpos] = EofChar) and not (buffer[bpos] in after) then
        quit(_pe, 'Unexpected end of file');

    result := '';
    while not ((buffer[bpos] in After) or (buffer[bpos] = EofChar))  do
    begin
        result := result + nextchar;
    end;
end;

function InStream.ReadInteger: integer;
var 
    help: string;
    code: integer;
begin
    while (buffer[bpos] in NumberBefore) do skipchar;

    if (buffer[bpos] = EofChar) then
        quit(_pe, 'Unexpected end of file - integer expected');

    help := '';
    while not (buffer[bpos] in NumberAfter) do 
        help := help + nextchar;
    val(help, result, code);
    if code <> 0 then Quit(_pe, 'Expected integer instead of "' + help + '"');
end;

function InStream.ReadLongint: integer;
var 
    help: string;
    code: integer;
begin
    while (buffer[bpos] in NumberBefore) do skipchar;

    if (buffer[bpos] = EofChar) then
        quit(_pe, 'Unexpected end of file - integer expected');

    help := '';
    while not (buffer[bpos] in NumberAfter) do 
        help := help + nextchar;
    val(help, result, code);
    if code <> 0 then Quit(_pe, 'Expected integer instead of "' + help + '"');
end;

function InStream.ReadReal: extended;
var 
    help: string;
    code: integer;
begin
    help := ReadWord (NumberBefore, NumberAfter);
    val(help, result, code);
    if code <> 0 then Quit(_pe, 'Expected real instead of "' + help + '"');
end;

procedure InStream.skip(setof: CharSet);
begin
    while (buffer[bpos] in setof) and (buffer[bpos] <> eofchar) do skipchar;
end;

function InStream.eof: boolean;
begin
    eof := buffer[bpos] = eofChar;
end;

function InStream.seekEof: boolean;
begin
    while (buffer[bpos] in Blanks) do skipchar;
    seekeof := buffer[bpos] = EofChar;
end;

function InStream.eoln: boolean;
begin
    eoln:= buffer[bpos] in eolnChar;
end;

function InStream.SeekEoln: boolean;
begin
    skip([' ', #9]);
    seekEoln := eoln;
end;

procedure InStream.nextLine;
begin
    while not (buffer[bpos] in eolnChar) do skipchar;
    if buffer[bpos] = #13 then skipchar; 
    if buffer[bpos] = #10 then skipchar; 
end;

function InStream.ReadString: string;
begin
    readstring := ReadWord([], lineAfter);
    nextLine;
end;

procedure InStream.close;
begin
    if opened then system.close(f);
    opened := false;
end;

initialization
    if sizeof(integer) <> 4 then
        quit(_fail, '"testlib" unit assumes "sizeof(integer) = 4"');

    if (ParamCount < 2) or (ParamCount > 5) then
        quit(_fail, 'Program must be run with the following arguments: ' +
            '<input-file> <output-file> <answer-file> [<report-file> [<-appes>]]');

    case ParamCount of
        2, 3: 
            begin
                ResultName := '';
                AppesMode := false;
            end;
        4: 
            begin
                ResultName := ParamStr(4);
                AppesMode := false;
            end;
        5: begin
                if uppercase(ParamStr(5)) <> '-APPES' then
                    quit(_fail, 'Program must be run with the following arguments: ' +
                        '<input-file> <output-file> <answer-file> [<report-file> [<-appes>]]');
                ResultName := ParamStr(4);
                AppesMode := true;
           end;
    end; { case }

   inf.init (ParamStr (1), _Input);
   if (ParamCount > 2) then begin
     ouf.init (ParamStr (2), _Output);
     ans.init (ParamStr (3), _Answer);
   end else begin
     ans.init (ParamStr (2), _Answer);
   end;
end.
