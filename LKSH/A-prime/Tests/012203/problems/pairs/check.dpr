uses
    testlib, sysutils;

type
    int = longint;

const
    MAXN = 250;
    MAXM = 250;

var
    n, m, tmp, pa, ja, u, v, i: int;
    a: array [1..MAXN, 1..MAXM] of boolean;
    lm: array [1..MAXN] of boolean;
    rm: array [1..MAXM] of boolean;

begin
    n := inf.readlongint;
    m := inf.readlongint;
    for i := 1 to n do begin
        tmp := inf.readlongint;
        while (tmp <> 0) do begin
            a[i][tmp] := true;
            tmp := inf.readlongint;
        end;
    end;
    pa := ouf.readlongint;
    ja := ans.readlongint;
    for i := 1 to pa do begin
        u := ouf.readlongint;
        v := ouf.readlongint;
        if ((u < 1) or (u > n)) then
            quit(_wa, format('Edge #%d: first index is invalid', [i]));

        if ((v < 1) or (v > m)) then
            quit(_wa, format('Edge #%d: second index is invalid', [i]));

        if ((lm[u]) or (rm[v])) then
            quit(_wa, 'Output is not a valid matching');

        lm[u] := true;
        rm[v] := true;
    end;
    if (pa < ja) then
        quit(_wa, 'Matching size is too small');

    if (pa > ja) then
        quit(_fail, 'Participant found matching of greater size than jury');

    quit(_ok, format('n = %d, m = %d, matching size = %d', [n, m, ja]));
end.
