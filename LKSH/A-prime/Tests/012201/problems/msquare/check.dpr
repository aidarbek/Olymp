uses testlib;
var
  dd:array[1..16] of longint;
  mm:array[1..4,1..4]of longint;
  i, j, k, a:integer;
  s:string;
begin
 for i:=1 to 16 do dd[i]:=inf.readinteger;
 ans.skip(blanks);
 if (ans.curchar='N') then
   begin
     ouf.skip(blanks);
     s:=ouf.readstring;
     if s = 'NO SOLUTION' then quit(_ok,'') else
     begin
       if (length(s)>0) and (s[1] in ['0'..'9']) then quit(_WA,'Incorrect example!') else quit(_PE,'Strange output');
     end;
   end;
 for i:=1 to 4 do
   for j:=1 to 4 do
     mm[i,j]:=ouf.readinteger;

 for i:=1 to 4 do
   for j:=1 to 4 do
     begin
       for k:=1 to 16 do
         if mm[i,j] = dd[k] then break;
       if mm[i,j] <> dd[k] then quit(_Wa,'Extra numbers');
       dd[k]:=-dd[k];
     end;
 a:=mm[1,1]+mm[1,2]+mm[1,3]+mm[1,4];
 for i:=1 to 4 do
   begin
     k:=0;
     for j:=1 to 4 do
       k:=k+mm[i,j];
     if a<>k then quit(_Wa,'Incorrect example');
     k:=0;
     for j:=1 to 4 do
       k:=k+mm[j,i];
     if a<>k then quit(_Wa,'Incorrect example');
   end;
 quit(_Ok,'');
end.
