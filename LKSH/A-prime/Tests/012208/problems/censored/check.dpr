uses
  testlib, sysutils;

var
  ja, pa: string;
  i: longint;
  l: longint;

begin 
  pa := ouf.readstring;
  ja := ans.readstring;
  if pa <> ja then
    quit(_wa, 'expected: ' + ja + ', found: ' + pa + '');
  QUIT ( _OK, 'Ok' );
end.
