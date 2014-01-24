echo off
for %%i in (1,2,3,4,5,6,7,8,9) do (
ren kuglice.in.%%i 0%%i
ren kuglice.out.%%i 0%%i.a
)
ren kuglice.in.10 10
ren kuglice.out.10 10.a
