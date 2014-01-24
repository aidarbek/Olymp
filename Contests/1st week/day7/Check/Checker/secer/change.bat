echo off
for %%i in (1,2,3,4,5,6,7,8,9) do (
ren secer.in.%%i 0%%i
ren secer.out.%%i 0%%i.a
)
ren secer.in.10 10
ren secer.out.10 10.a
