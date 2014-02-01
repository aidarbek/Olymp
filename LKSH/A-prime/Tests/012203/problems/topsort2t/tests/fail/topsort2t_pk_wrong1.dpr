{$q+,r+,s+,i+,o+}
{$APPTYPE CONSOLE}
{$M 10000000}
{$mode delphi}
{Слишком маленькие массивы}
type pedge=^tedge;
     tedge=record v:integer; next:pedge; end;
     
var gr:array[1..10000] of pedge;
    was:array[1..10000] of integer;
    ans:array[1..10000] of integer;
    nans:integer;
    f:text;
    i:integer;
    u,v:integer;
    n,m:integer;
    p:pedge;
    
procedure outno;
begin
assign(f,'topsort2t.out');rewrite(f);
writeln(f,-1);
close(f);
halt;
end;
    
procedure find(i:integer);
var p:pedge;
begin
if was[i]=2 then exit;
if was[i]=1 then outno;
was[i]:=1;
p:=gr[i];
while p<>nil do begin
      find(p^.v);
      p:=p^.next;
end;
was[i]:=2;
ans[nans]:=i;
dec(nans);
end;

begin
assign(f,'topsort2t.in');reset(f);
read(f,n,m);
assert((1<=n)and(n<=100000),'Wrong n');
assert((1<=m)and(m<=100000),'Wrong m');
fillchar(gr,sizeof(gr),0);
for i:=1 to m do begin
    read(f,u,v);
    assert((1<=u)and(u<=n));
    assert((1<=v)and(v<=n));
    new(p);
    p^.v:=v;
    p^.next:=gr[u];
    gr[u]:=p;
end;
close(f);
fillchar(was,sizeof(was),0);
nans:=n;
for i:=1 to n do
    find(i);
assign(f,'topsort2t.out');rewrite(f);
for i:=1 to n do
    write(f,ans[i],' ');
close(f);
end.