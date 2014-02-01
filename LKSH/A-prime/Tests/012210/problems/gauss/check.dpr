{$apptype CONSOLE}

uses
  SysUtils,testlib;

const
  maxN = 100;
  eps = 1e-3;

type
  float = extended;

var
  n : integer;
  i, j : integer;
  a : array[1..maxN, 1..maxN] of float;
  b, x : array[1..maxN] of float;
  err, s : float;

begin
  n := inf.ReadInteger;
  for i := 1 to n do begin
    for j := 1 to n do
      a[i,j] := inf.ReadReal;
    b[i] := inf.ReadReal;
  end;

  for i := 1 to n do
    x[i] := ouf.ReadReal;

  err := 0;
  for i := 1 to n do begin
    s := 0;
    for j := 1 to n do
      s := s + x[j] * a[i,j];
    err := err + sqr (s - b[i]);
  end;
  err := sqrt (err);

  s := 0;
  for i := 1 to n do
    s := s + sqr (x[i]);
  s := sqrt (s);

  if err / (s + 0.1) > eps then
    Quit (_WA, 'Relative error is ' + format('%0.2f',[err / (s + 0.1) * 100]) + '%')
  else
    Quit (_Ok, '|x|=' + format('%0.2f',[s]) + ', err=' + format('%0.2f',[err]) );

end.
