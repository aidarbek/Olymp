{$q+,r+,s+,i+,o+}
{$APPTYPE CONSOLE}
uses SysUtils,testlib;
const maxN=100000;
      maxM=1000000;
var n,m:integer;
    bad:array[1..maxM] of record a,b:integer; end;
    nt:array[1..maxN*2] of integer;
    take:array[1..maxN*2] of integer;
    a:array[1..maxN] of integer;
    i:integer;
    u,v:integer;
    was:array[1..maxN*2] of integer;
    
begin
n:=inf.readlongint;
m:=inf.readlongint;
for i:=1 to n do begin 
    u:=inf.readlongint;
    v:=inf.readlongint;
    nt[u]:=v;
    nt[v]:=u;
end;
for i:=1 to m do begin
    bad[i].a:=inf.readlongint;
    bad[i].b:=inf.readlongint;
end;
a[1]:=ouf.readlongint;
if a[1]=-1 then begin
   if ans.readlongint=-1 then quit(_ok,'-1')
   else quit(_wa,'-1, when solution exists');
end;
for i:=2 to n do
    a[i]:=ouf.readlongint;
fillchar(was,sizeof(was),0);
for i:=1 to n do begin
    if (a[i]<=0)or(a[i]>2*n) then
       quit(_pe,'Strange number of participant: '+inttostr(a[i]));
    if was[a[i]]<>0 then
       quit(_pe,'Participant '+inttostr(a[i])+' duplicates');
    if was[nt[a[i]]]<>0 then
       quit(_wa,'Participant '+inttostr(a[i])+' together with its opponent '+inttostr(nt[a[i]]));
    was[a[i]]:=1;
end;
for i:=1 to m do
    if (was[bad[i].a]=1)and(was[bad[i].b]=1) then
       quit(_wa,'Condition #'+inttostr(i)+' not satisfied');
quit(_ok,'N='+inttostr(n));
end.