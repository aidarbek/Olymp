program checka;

uses
    testlib, sysutils;
    
const
    maxn = 100000;
    
type
    tanswer = array [1..maxn] of longint;
    
procedure sort(var a: tanswer; l, r: longint);
var
    i, j, x, t: longint;
begin
    x := a[l + random(r - l + 1)];
    i := l;
    j := r;
    while i <= j do
    begin
        while a[i] < x do inc(i);
        while a[j] > x do dec(j);
        if i <= j then
        begin
            t := a[i]; a[i] := a[j]; a[j] := t;
            inc(i); dec(j);
        end;
    end;
    if l < j then sort(a, l, j);
    if i < r then sort(a, i, r);
end;

var
    ja, pa: longint;
    jc, pc: tanswer;
    i: longint;
    
begin
    ja := 0;
    while not ans.seekeof do
    begin
        inc(ja);
        jc[ja] := ans.readlongint;
    end;
    
    pa := 0;
    while (not ouf.seekeof) and (pa < ja) do
    begin
        inc(pa);
        pc[pa] := ouf.readlongint;
    end;
    
    while not ouf.seekeof do
    begin
        inc(pa);
        pc[pa] := ouf.readlongint;
    end;
    
    for i:=2 to pa do
      if pc[i]=pc[i-1] then quit(_pe,'Participant wrote number '+inttostr(pc[i])+' twice');

    if (ja <> pa) then
        quit(_wa, 'Wrong count, expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));
        
    sort(jc, 1, ja);
    sort(pc, 1, pa);
    
    for i := 1 to ja do
    begin
        if jc[i] < pc[i] then
            quit(_wa, 'Variant ' + inttostr(jc[i]) + ' omitted');            
        if jc[i] > pc[i] then
            quit(_wa, 'Variant ' + inttostr(pc[i]) + ' unexpected');            
    end;
    
    quit(_ok, inttostr(ja) + ' variants');
end.
