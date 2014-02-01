uses testlib;
var jury, cont:string;
begin
  while not ans.seekeof do
  begin
    jury:=ans.readstring;
    cont:=ouf.readstring;
    if (cont<>'NO') and (cont<>'YES') then quit (_PE, 'YES or NO required');
    if jury<>cont then quit (_WA, 'Jury: '+jury+', Contestant: '+cont);
  end;
  quit (_OK, '');
end.