REM
REM Keenan's Hack to remove intermediate files
REM Designed to work for C++ or C# visual studio projects
REM
REM If you find a way to enhance, 
REM please return updates to ekeenan2@cdm.depaul.edu
REM

REM Set the current directory as AZUL_PATH environmental var
for %%I in (.) do set CurrDirName=%%~fI
echo %CurrDirName%

SETX AZUL_PATH "%CurrDirName%"


REM cleanup root directory

    if exist ..\Azul rmdir /S /Q ..\Azul
    if exist *.user del /F /s *.user
    if exist Azul rmdir /S /Q Azul
    if exist Logs rmdir /S /Q Logs
    if exist Debug rmdir /S /Q Debug
    if exist Release rmdir /S /Q Release
    if exist x64 rmdir /S /Q x64
    if exist ipch rmdir /S /Q ipch
    if exist .vs rmdir /S /Q .vs
    del /F /q .\Data\*.azul
    del /F /q .\Data\*.json
    del /F /q .\Libs\ProtoBuf\src\*.pb.*

    if exist shaders\compiled rmdir /S /Q shaders\compiled

    if exist *.suo del /F /S /A:H *.suo
    if exist *.sdf del /F /S *.sdf
    if exist *.suo del /F /S *.suo
    if exist *.db del /F *.db

REM call each projects cleanme

cd NeelamEngine
call "CleanMe.Bat"
cd ..

cd NeelamEditor
call "CleanMe.Bat"
cd ..

