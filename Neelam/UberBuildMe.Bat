@echo off
setlocal

pushd "%~dp0"

call "UberCleanAll.Bat"

call "Vendor\bin\premake\premake5.exe" vs2022

popd
endlocal
