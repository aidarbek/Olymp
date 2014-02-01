{ $Id: test.dpr 13 2007-11-01 16:51:35Z Стандартный $ }
{$q+,r+,s+,i+,o+}
{$APPTYPE CONSOLE}
uses SysUtils,testlib;
var a,b:longint;
begin
a:=ouf.readlongint;
b:=ans.readlongint;
if a<>b then
   quit(_wa,inttostr(a)+' instead of '+inttostr(b))
else quit(_ok,inttostr(a));
end.