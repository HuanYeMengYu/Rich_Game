@echo off
setlocal enabledelayedexpansion

chcp 65001
for /d %%d in (test_3\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt" > out.txt
            main.exe "%%d" < "%%d\input.txt" > out.txt
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试三组样例ing
echo.
python test3.py test_3

echo 所有操作完成
pause