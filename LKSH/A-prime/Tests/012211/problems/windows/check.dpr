{$A+,B-,D+,E-,F-,G+,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V-,X+,Y+}
uses testlib, SysUtils;

const MaxN=50000;
      MaxC=100000;

type iarr=array [1..MaxN] of integer;
     parr=^iarr;

var x1, y1, x2, y2:parr;
    n:integer;

function answer (var f:instream):integer;
var v, xc, yc, i, r:integer;
begin
  v:=f.readlongint;
  xc:=f.readlongint; yc:=f.readlongint;
  r:=0;
  for i:=1 to n do
    if (x1^[i]<=xc) and (y1^[i]<=yc) and (xc<=x2^[i]) and (yc<=y2^[i]) then
      inc (r);
  if r<>v then f.quit(_wa, 'Wrong number of windows in point(' + inttostr(xc) + ',' + inttostr(yc) + ') : '+inttostr (v)+' instead of '+inttostr (r));
  answer:=v;
end;

var i:integer;
    jury, cont:integer;

begin
  new (x1); new (y1); new (x2); new (y2);
  n:=inf.readlongint; 
  for i:=1 to n do begin
    x1^[i]:=inf.readlongint;
    y1^[i]:=inf.readlongint;
    x2^[i]:=inf.readlongint;
    y2^[i]:=inf.readlongint;
//    inf.reql (Reject);
    if not ((x1^[i]<x2^[i]) and (y1^[i]<y2^[i])) then begin
    	quit (_fail, 'bug in test');
    end;
  end;
  jury:=answer (ans); cont:=answer (ouf);
  if cont>jury then quit (_fail, 'he''s won')
  else
  if jury>cont then quit (_wa, 'Participant has the worse answer')
  else
  quit (_ok, '');
end.
