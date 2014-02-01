uses 
	testlib, sysutils;

var
	n, ja, pa: int64;
begin
	n := 0;
	while not ans.seekeof do begin
		inc(n);
		ja := ans.readint64;
		pa := ouf.readint64;
		if ja <> pa then
			quit(_wa, 'number ' + inttostr(n) + ' - expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));
	end;
	quit (_ok, '');
end.
