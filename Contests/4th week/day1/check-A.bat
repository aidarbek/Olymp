@echo off

set problem=A

echo Problem %problem%

del result*.txt > nul
echo 0 > result.txt
echo 0 > result_expanded.txt

for %%i in (problems\%problem%\??) do (
        cls

        echo %1
        echo Test - %%i

        del %problem%.in %problem%.out 2> nul

        copy %%i %problem%.in > nul 

        bin\runexe.exe -t 2s -m 64M %1
        if not errorlevel 1 (
                problems\%problem%\check %%i %problem%.out %%i.a
                if not errorlevel 1 (
                	bin\inc
                	bin\save_result ok
                ) else (
                	bin\save_result wa
                )
        ) else (
        	echo !!! Time or memory limit exceeded
           	bin\save_result oe
        )

        del %problem%.in %problem%.out 2> nul

)

cls

echo Problem %problem%
echo Passed tests number and points:
type result.txt
bin\count 21 100
bin\print_result

pause
