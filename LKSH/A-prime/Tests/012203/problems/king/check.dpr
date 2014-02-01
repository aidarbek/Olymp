{$O-,Q+,R+}
{$APPTYPE CONSOLE}
uses testlib, sysutils;

const MaxN=2000;

type integer=longint;
     indata=array [1..MaxN, 1..MaxN] of boolean;

var n:integer;


procedure answer (var f:instream; var g:indata; wa:TResult);
var i, j, k, l:integer;
begin
  for i:=1 to n do begin
    k:=f.readlongint; 
    if (k<1) or (k>n) then quit (wa, 'Invalid number of edges ('+inttostr (k)+') from '+inttostr (i)+'-th vertex');
    for j:=1 to k do begin 
      l:=f.readlongint; 
      if (l<1) or (l>n) then quit (wa, 'Invalid number of vertex: '+inttostr (l));
      if g[i, l] then quit (wa, 'Repeated edge ('+inttostr (i)+' -> '+inttostr (l)+')');
      g[i, l]:=true;
    end;
  end;
end;


var g1, g2:indata;
    i, j:integer;

begin
  n:=inf.readlongint;
  answer (ans, g1, _Fail);
  answer (ouf, g2, _WA);
  for i:=1 to n do
    for j:=1 to n do
      if g1[i, j]<>g2[i, j] then
        quit (_wa, 'Answer mismatch for edge ('+inttostr (i)+' -> '+inttostr (j)+')');
  quit (_ok, inttostr (n)+' vertices');
end.
