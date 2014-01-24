echo off
for %%i in (1,2,3,4,5,6,7,8,9) do (
ren gitara.in.%%i 0%%i
ren gitara.out.%%i 0%%i.a
)
ren gitara.in.10 10
ren gitara.out.10 10.a
