echo off
for %%i in (1,2,3,4,5,6,7,8,9) do (
ren postar.in.%%ib 1%%i
ren postar.out.%%ib 1%%i.a
)
ren postar.in.10b 20
ren postar.out.10b 20.a
