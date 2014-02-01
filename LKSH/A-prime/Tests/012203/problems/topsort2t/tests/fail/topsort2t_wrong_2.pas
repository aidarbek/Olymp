{
Решение кого-то из школьников, которое дает WA на тесте 20
В чем ошибка, я не разбирался
}

program ex_topsort;

{$APPTYPE CONSOLE}
{$M 10000000,1024}
{$mode delphi}

uses
  SysUtils;
var
 n, m, s, f, i, ansl: integer;
 g: array[1..100000] of array of integer;
 len, ans, color: array[1..100000] of integer;
 used: array[1..100000] of boolean;
 procedure dfs(v: integer);
 var i: integer;
 begin
    used[v] := true;
    for i := 1 to len[v] do
      if not used[g[v][i]] then
        dfs(g[v][i]);
    inc(ansl);
    ans[ansl] := v;      
 end;

 procedure topsort;
 var i: integer;
 begin
   fillchar(used, sizeof(used), 0);
   for i := 1 to n do
     begin
       if not used[i] then
         dfs(i);
     end;
 end;

 procedure cycle(v: integer);
 var i: integer;
 begin
   color[v] := 1;
   for i := 1 to len[v] do
     if  color[g[v][i]] = 0  then
       cycle(g[v][i])
     else
       if color[g[v][i]] = 1 then
         begin
           writeln(-1);
           halt;
         end;

     
   color[v] := 2;  
 end;

begin
  assign(input, 'topsort2t.in'); reset(input);
  assign(output, 'topsort2t.out'); rewrite(output);

  read(n, m);
  fillchar(len, sizeof(len), 0);
  for i := 1 to m do
    begin
      read(s, f);
      if length(g[s]) < len[s] + 1 then
        setlength(g[s], (len[s]+1)*10);
      inc(len[s]);
      g[s][len[s]] := f;
    end;
  fillchar(color, sizeof(color), 0);

  for i := 1 to n do
    if color[i] = 0 then
      cycle(i);
  
  topsort;

  for i := ansl downto 1 do
    write(ans[i], ' ');

  close(input);
  close(output);

end.
