@echo off
echo Compiling program...
gcc -o main.exe *.c

if %ERRORLEVEL% neq 0 (
    echo Compilation error!
    pause
    exit /b 1
)

echo Compilation successful!
echo.
echo Running tests...
echo ========================

for %%f in (Tests\*.txt) do (
    echo.
    echo Testing file: %%f
    echo ------------------------
    main.exe "%%f"
    echo.
)

echo ========================
echo All tests completed!
pause