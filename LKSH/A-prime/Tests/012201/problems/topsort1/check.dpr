{$apptype console}
{$o-}
uses testlib,SysUtils;


const
  maxm = 100000;
var a,b,vert:array [1..maxm] of longint;
  n,m,u,v:longint;
  i,first:longint;
  ca,ja:longint;
procedure swap(var a,b:longint);
var
  t:longint;
begin
  t:=a;a:=b;b:=t;
end;

procedure qsort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l;j:=r;x:=a[(l+r) div 2];y:=b[(l+r) div 2];
  repeat
    while (a[i]<x) or ((a[i]=x)and(b[i]<y)) do inc(i);
    while (a[j]>x) or ((a[j]=x)and(b[j]>y)) do dec(j);
    if i<=j then begin
      swap(a[i],a[j]);
      swap(b[i],b[j]);
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then qsort(i,r);
  if j>l then qsort(l,j);
end;

procedure test(var aa,bb:longint);
var
  l,r,mid:longint;
begin
  l:=1;
  r:=m;
  while l <= r do Begin
      mid := (l + r) div 2;
      if a[mid] < aa then l := mid + 1;
      if a[mid] > aa then r := mid - 1;
      if (a[mid] = aa) then begin
        if b[mid] < bb then l := mid + 1;
        if b[mid] > bb then r := mid - 1;
        if b[mid] = bb then break;
      end;
    end;
    if (a[mid] <> aa) or (b[mid] <> bb) Then
      quit(_wa,'net rebra');
end;

                                               
var
  k:longint;
begin
  n:=inf.Readlongint;
  m:=inf.readlongint;
  for i:=1 to m do begin
    a[i]:=inf.Readlongint;
    b[i]:=inf.Readlongint;
  end;

  k:=ouf.Readlongint;
  ja := ans.readlongint;

  if (ja=-1) then begin
    if k=-1 then quit(_ok,'') else quit(_wa,'');
  end;

  vert[k]:=1;

  for i:=2 to n do begin

    vert[ouf.Readlongint]:=i;
  end;

  for i:=1 to m do begin
    if vert[a[i]]>vert[b[i]]then quit(_wa,'');
  end;

  quit(_ok,'');
end.