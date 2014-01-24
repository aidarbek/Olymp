var a, b: longint;
begin
	assign(input, 'A.in');
	reset(input);
	assign(output, 'A.out');
	rewrite(output);

	readln(a, b);
	writeln(a + b);

	close(output);
end.
