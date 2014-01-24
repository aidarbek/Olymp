del res.txt
echo off
for %%i in (??) do (
Copy %%i koki.in
run -t 1s -m 64M a
sanjar koki.in koki.out %%i.a >> res.txt
)
