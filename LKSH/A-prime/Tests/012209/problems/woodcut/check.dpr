{$q+,r+,s+,i+}
{$define exact}
{$APPTYPE CONSOLE}
uses SysUtils,testlib;
const maxn=100000;
type pedge=^tedge;
     tedge=record
             v:integer;
             num:integer;
             next:pedge;
           end;
var n,r:integer;
    gr:array[1..maxn] of pedge;
    gf:array[1..maxn] of integer;
    i:integer;
    a,b:integer;
    cans,jans:integer;
    cedje:integer;

procedure add(i,j:integer;n:integer);
var p:pedge;
begin
new(p);
p^.v:=j;
p^.num:=n;
p^.next:=gr[i];
gr[i]:=p;
end;

procedure calc(v,p:integer);
var ed:pedge;
begin
gf[v]:=0;
ed:=gr[v];
while ed<>nil do begin
      if (ed^.v<>p)and(ed^.num<>cedje) then begin
         calc(ed^.v,v);
         gf[v]:=gf[v] xor (gf[ed^.v]+1);
      end;
      ed:=ed^.next;
end;
end;

begin
fillchar(gr,sizeof(gr),0);
n:=inf.readlongint;
r:=inf.readlongint;
for i:=1 to n-1 do begin
    a:=inf.readlongint;
    b:=inf.readlongint;
    add(a,b,i);
    add(b,a,i);
end;
cans:=ouf.readlongint;
if (cans<>1)and(cans<>2) then
   quit(_pe,'Strange number in output: '+inttostr(cans));
jans:=ans.readlongint;
if cans=2 then begin
   if jans=2 then
      quit(_ok,'Lose');
   quit(_wa,'You weren''t able to win, but it is possible to');
end;
cedje:=ouf.readlongint;
if (cedje<=0)or(cedje>=n) then
   quit(_pe,'Strange edge number in output: '+inttostr(cedje));
calc(r,0);
if gf[r]<>0 then
   quit(_wa,'You can''t win with this move');
if jans=2 then
   quit(_fail,'Solution found!');
quit(_ok,'N='+inttostr(n));
end.
