uses SysUtils, testlib;
type integer=longint;

const MaxN=3000;
      MaxM=100000;

var n:integer;
    z:array [1..MaxN] of boolean;
    g:array [1..MaxN, 1..MaxN] of boolean;

procedure poisk (u:integer);
var i:integer;
begin
  z[u]:=true;
  for i:=1 to n do
    if not z[i] and g[u, i] then poisk (i);
end;


function answer (var f:instream):integer;
var i, x:integer;
begin
  fillchar (z, sizeof (z), 0);
  Result:=f.readLongint;
  for i:=1 to Result do begin
    x:=f.readLongint;
    if (x<1) or (x>n) then f.quit (_WA, 'wrong number of house: '+ intToStr(x));
    if z[x] and (@f=@ans) then f.quit (_Fail, 'Bad jury answer');
    if not z[x] then poisk (x);
  end;
  for i:=1 to n do if not z[i] then f.quit (_WA, intToStr(i)+' is unreachable');
end;



var m, a, b, i, jury, cont:integer;

begin
    n:= inf.readLongint();
    m:= inf.readLongint();
    for i := 1 to m do begin
        a := inf.readLongint(); 
        b := inf.readLongint();
        g[b, a]:=true;
    end;

    jury := answer(ans);
    cont := answer(ouf);

    if jury < cont then begin
        quit(_WA, 'Not optimal: ' + intToStr(cont) + ' instead of ' + intToStr(jury));
    end;
    if cont < jury then begin
        quit(_Fail, 'Too optimal: ' + intToStr(cont) + ' instead of ' + intToStr(jury));
    end;
    quit(_ok, intToStr(jury) +' stations');
end.