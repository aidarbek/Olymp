{$apptype console}
{$o-}
uses testlib,SysUtils;


const
  maxm = 100000;
var a,b,vert:array [1..maxm] of longint;
  n,m,u,v:longint;
  i,first:longint;
  ca,ja:longint;

                                               
var
  k:longint;
begin
  n:=inf.Readlongint;
  if (n<=0) or (n>100000) then quit(_pe,'Wrong N');
  m:=inf.readlongint;
  if (m<0) or (m>100000) then quit(_pe,'Wrong M');
  
  for i:=1 to m do begin
    a[i]:=inf.Readlongint;
    if (a[i]<1)or(a[i]>n) then quit(_pe,'Wrong first vertex of an edge '+inttostr(i));
    b[i]:=inf.Readlongint;
    if (b[i]<1)or(b[i]>n) then quit(_pe,'Wrong second vertex of an edge '+inttostr(i));
  end;
  
  if (not inf.seekeof) then quit(_pe,'Extra information in input');

  ja := ans.readlongint;
  if (ja=-1) then quit(_ok,'');

  vert[ja]:=1;

  for i:=2 to n do begin
    vert[ans.Readlongint]:=i;
  end;

  for i:=1 to m do begin
    if vert[a[i]]>vert[b[i]]then quit(_wa,'Edge '+inttostr(i)+' goes in wrong direction');
  end;
  
  quit(_ok,'');
end.