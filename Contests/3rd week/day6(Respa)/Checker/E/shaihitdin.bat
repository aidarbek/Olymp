del res.txt
echo off
for %%i in (??) do (
Copy %%i in
run -t 2s -m 64M a
sanjar in out %%i.a >> res.txt
)
