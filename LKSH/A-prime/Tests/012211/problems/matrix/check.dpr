{$O-,Q+,R+}
uses testlib;
type integer=longint;

var n:integer;

const MaxN=239;
      MaxV=1000000;

var m:array [1..MaxN, 1..MaxN] of integer;

function answer (var f:instream):integer;
var v:integer;
    f1, f2:array [1..MaxN] of boolean;
    a, b:integer;
    i, cnt:integer;
begin
  v:=f.readlongint; cnt:=0;
  fillchar (f1, sizeof (f1), 0);
  fillchar (f2, sizeof (f2), 0);
  for i:=1 to n do begin
    a:=f.readlongint; b:=f.readlongint;
    if (a<1) or (a>n) or (b<1) or (b>n) then f.quit (_wa, 'invalid values');
    if f1[a] or f2[b] then f.quit (_wa, 'already visited');
    f1[a]:=true; f2[b]:=true;
    inc (cnt, m[a, b]);
  end;
  if cnt<>v then f.quit (_wa, 'counter mismatch');
  answer:=cnt;
end;

var jury, cont:integer;
    i, j:integer;

begin
  n:=inf.readlongint;
  for i:=1 to n do begin
    for j:=1 to n do begin
      m[i, j]:=inf.readlongint;
    end;
  end;
  jury:=answer (ans); cont:=answer (ouf);
  if jury<cont then quit (_wa, 'too large') else
  if jury>cont then quit (_fail, 'file system check');
  quit (_ok, '');
end.