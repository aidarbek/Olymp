
uses testlib, sysutils;
const
    max_n = 1000;

var
    i, j, k, v, pv, n, c: longint;
    a: array [1..max_n, 1..max_n] of longint;
    u: array [1..max_n, 1..max_n] of boolean;
    f: boolean;
begin
    n := inf.readInteger;

    c := 0;
    for i := 1 to n do begin
        k := inf.readLongInt;
        c := c + k;
        for j := 1 to k do begin
            v := inf.readLongInt;
            inf.readLongInt;
            inc(a[i][v]);
            u[i][v] := true;
        end;
    end;

    for i := 1 to n do begin
        for j := i + 1 to n do begin
            if a[i][j] <> a[j][i] then begin
                quit(_wa, format('Дороги из %d в %d заданы неверно', [i, j]));
            end;
        end;
    end;

    k := ouf.readLongInt;
    if (k = -1) then begin
       if ans.readlongint = -1 then
          quit(_ok,'No solution')
       else quit(_wa,'-1 when solution exists');
    end;
    
    if (k < c div 2) then begin
        quit(_wa, 'Пройдены не все улицы');
    end;
    if (k > c div 2) then begin
        quit(_wa, 'Путь не оптимален');
    end;

    v := 0;
    f := false;
    for i := 0 to c div 2 do begin
        pv := ouf.readLongInt;
        if (pv < 0) or (pv > n) then begin
            quit(_wa, format('Шаг %d: Площадь номер %d не существует', [i, pv]));
        end;        
        if (v <> 0) then begin
            if not u[v][pv] then begin
                quit(_wa, format('Шаг %d: Нет дороги из %d в %d', [i, v, pv]));
            end;
            dec(a[v][pv]);
            f := f or (a[v][pv] < 0);
        end;
        v := pv;
    end;
    if f then begin
        quit(_wa, 'Не все дороги пройдены');
    end;
    quit(_ok, '');
end.           
