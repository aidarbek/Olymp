echo off
for %%i in (1,2,3,4,5,6,7,8,9) do (
ren upit.in.%%i 0%%i
ren upit.out.%%i 0%%i.a
)
ren upit.in.10 10
ren upit.out.10 10.a
