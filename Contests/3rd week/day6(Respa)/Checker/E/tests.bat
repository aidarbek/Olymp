del res.txt
echo off
for %%i in (??) do (
Copy %%i cocai.in
run -t 2s -m 64M a
fcmp cocai.in cocai.out %%i.a >> res.txt
)
