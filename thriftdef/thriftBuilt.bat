@echo off
TITLE  thrift-compliler-thriftfile
echo=
for %%i in (*.thrift) do (
    echo built %%i framework code
    thrift -gen go %%i
    set filename=%%i
    echo "%%i"
    set fl=%filename:~0,-7%
    echo %fl%
    if exist "..\gen-go\%fl%"  RD /S/Q  "..\gen-go\%fl%"
    move "gen-go\%fl%" "..\gen-go\"
    rem 完成
)
PAUSE>NUL