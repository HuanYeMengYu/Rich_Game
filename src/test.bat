@echo off
setlocal enabledelayedexpansion

chcp 65001
for /d %%d in (walk\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt" > out.txt
            main.exe "%%d" < "%%d\input.txt" > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试行走ing
echo.
python test.py walk
echo.


for /d %%d in (sell\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt" > out.txt
            main.exe "%%d" < "%%d\input.txt" > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试售卖ing
echo.
python test.py sell
echo.


for /d %%d in (gift\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt" > out.txt
            main.exe "%%d" < "%%d\input.txt" > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试礼品屋ing
echo.
python test.py gift


for /d %%d in (tool\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试道具使用ing
echo.
python test.py tool
echo.


for /d %%d in (upgrade\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试升级地产ing
echo.
python test.py upgrade
echo.


for /d %%d in (bankrupt\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试破产ing
echo.
python test.py bankrupt
echo.


for /d %%d in (gameover\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试游戏结束ing
echo.
python test.py gameover
echo.


for /d %%d in (buy_house\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试买房ing
echo.
python test.py buy_house
echo.


for /d %%d in (buy_tool\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试买道具ing
echo.
python test.py buy_tool
echo.


for /d %%d in (rent\test*) do (
    if exist "%%d\input.txt" (
        if exist "%%d\user.json" (
            @REM echo 使用当前目录的 main.exe:
            echo main.exe "%%d" ^< "%%d\input.txt " > out.txt
            main.exe "%%d" < "%%d\input.txt " > out.txt
            @REM main.exe "%%d" < "%%d\input.txt"
        ) else (
            echo 警告: %%d 文件夹中没有找到 user.json
        )
    ) else (
        echo 警告: %%d 文件夹中没有找到 input.txt
    )
    @REM echo.
)
echo 测试租金ing
echo.
python test.py rent
echo.


echo 所有操作完成
pause