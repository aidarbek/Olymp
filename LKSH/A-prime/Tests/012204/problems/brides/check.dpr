{$apptype console}

program check_brides;

uses
    testlib, sysutils;

const
    maxn = 200;
    maxm = 2000;
    eps = 2.5e-5;
    
var
    ja, pa: extended;
    a, b, l, n, m, k, i, e, p, x, j, t: longint;
    head: array [1..maxn] of longint;
    src, dst, len, next, u: array [1..2*maxm] of longint;
    sum: longint;

begin
    DecimalSeparator := '.';

    ja := ans.readreal;
    pa := ouf.readreal;

    if pa < 0 then begin
        if ja < 0 then
            quit(_ok, '-1')
        else 
            quit(_wa, '-1 unexpected');
    end;

    if pa > ja + eps then quit(_wa, format('Minimum is %.5f, participant: %.5f', [ja, pa]));

    n := inf.readlongint;
    m := inf.readlongint;
    k := inf.readlongint;

    e := 0;
    for i := 1 to m do begin
        a := inf.readlongint;
        b := inf.readlongint;
        l := inf.readlongint;

        inc(e);
        next[e] := head[a];
        head[a] := e;
        len[e] := l;
        src[e] := a;
        dst[e] := b;
        u[e] := 0;

        inc(e);
        next[e] := head[b];
        head[b] := e;
        len[e] := l;
        src[e] := b;
        dst[e] := a;
        u[e] := 0;
    end;
    
    sum := 0;
    for i := 1 to k do begin
        //writeln(i,'-th step');
        p := ouf.readlongint;
        if (p>m) or (p<1) then quit(_pe,'Wrong number of roads');
        x := 1;
        for j := 1 to p do begin
            t := ouf.readlongint;
            if (t>m) or (t<1) then quit(_pe,'Wrong number of the road');
            if src[2 * t - 1] = x then begin
                if u[2 * t - 1] <> 0 then
                    quit(_wa, format('Sons %d and %d both were on the road %d.', [i, u[2 * t - 1], t]));
                u[2 * t - 1] := i;
                u[2 * t] := i;
                sum := sum + len[2 * t - 1];
                x := dst[2 * t - 1];
            end else if src[2 * t] = x then begin
                if u[2 * t] <> 0 then
                    quit(_wa, format('Sons %d and %d both were on the road %d.', [i, u[2 * t], t]));
                u[2 * t - 1] := i;
                u[2 * t] := i;
                sum := sum + len[2 * t];
                x := dst[2 * t];
            end else begin
                quit(_wa, format('Son %d used strange path (edge), e. g. vertex 1 isn''t the end of this son''s first edge.', [i]));
            end;
        end;
        if x <> n then
            quit(_wa, format('Son %d is not in city n...', [i]));
    end;

    if abs(sum / k - pa) > eps then
        quit(_wa, format('King said that it will be %.5f hours,  but it is %.5f', [pa, sum / k]));

    if (pa < ja - eps) or (ja < 0) then
        quit(_fail, format('Jury expected %.5f, but participant found %.5f', [ja, pa]));
    quit(_ok, format('%.5f', [pa]));
end.