uses
	testlib, sysutils;
var
	i, n, jv, pv: longint;
begin
	n := inf.readlongint;
	for i := 1 to n do begin
		jv := ans.readlongint;
		pv := ouf.readlongint;

		if jv <> pv then begin
			quit(_wa, format('number %d - expected: %d, found: %d', [i, jv, pv]));
		end;
	end;

	quit(_ok, '');
end.