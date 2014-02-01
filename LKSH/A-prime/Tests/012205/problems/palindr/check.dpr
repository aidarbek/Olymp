uses 
	testlib, sysutils;

var
	ja, pa: string;
begin
 	ja := ans.readstring;
 	pa := ouf.readstring;
 	if ja <> pa then
 		quit(_wa, 'expected: ' + ja + ', found: ' + pa);
	quit (_ok, '');
end.
