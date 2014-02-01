{$q+,r+,s+,i+,o+}
{$APPTYPE CONSOLE}
uses SysUtils,testlib;
var n,c,k:integer;
    jm,m:integer;
    a:array[1..1000] of integer;
    pn,nn:integer;
    ps:integer;
    i:integer;

begin
n:=inf.readlongint;
c:=inf.readlongint;
k:=inf.readlongint;
for i:=1 to n do
    a[i]:=inf.readlongint;
m:=ouf.readlongint;
if (m=-1) then begin
   if ans.readlongint=-1 then
      quit(_ok,'No solution')
   else quit(_wa,'No solution, when solution exists');
end;
if (m<0)or(m>n) then
   quit(_pe,'Strange number of coins: '+inttostr(m));
ps:=0;
pn:=0;
for i:=1 to m do begin
    nn:=ouf.readlongint;
    if (nn<=0)or(nn>n) then 
       quit(_pe,'Strange number of a coin: '+inttostr(nn));
    if a[nn]<0 then
       quit(_pe,format('Coin %d used more than one',[nn]));
    if (pn>=nn) then
       quit(_pe,'Coins not in increasing order');
    pn:=nn;
    ps:=ps+a[nn];
    a[nn]:=-1;
end;
if ps<>c then
   quit(_wa,'Wrong sum acquired');
jm:=ans.readlongint;
if jm<m then
   quit(_wa,'Non-optimal solution');
if jm>m then
   quit(_fail,'Found better solution');
quit(_ok,'N='+inttostr(n));
end.