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
    if exist *.sln del /F /Q *.sln
    if exist NeelamEngine\*.vcxproj del /F /Q NeelamEngine\*.vcxproj
    if exist NeelamEngine\*.vcxproj.filters del /F /Q NeelamEngine\*.vcxproj.filters
    if exist NeelamEngine\*.vcxproj.user del /F /Q NeelamEngine\*.vcxproj.user
    if exist Framework\*.vcxitems del /F /Q Framework\*.vcxitems
    if exist Framework\*.vcxitems.filters del /F /Q Framework\*.vcxitems.filters
    if exist Framework\*.vcxitems.user del /F /Q Framework\*.vcxitems.user
    if exist NeelamEditor\*.csproj.user del /F /Q NeelamEditor\*.csproj.user
    if exist *.user del /F /s *.user
    if exist Azul rmdir /S /Q Azul
    if exist Logs rmdir /S /Q Logs
    if exist Debug rmdir /S /Q Debug
    if exist Release rmdir /S /Q Release
    if exist x64 rmdir /S /Q x64
    if exist ipch rmdir /S /Q ipch
    if exist .vs rmdir /S /Q .vs
    REM del /F /q .\Data\*.azul
    REM del /F /q .\Data\*.json
    REM del /F /q .\Libs\ProtoBuf\src\*.pb.*

    REM if exist shaders\compiled rmdir /S /Q shaders\compiled

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

cd Libs\Math
call "CleanMe.Bat"
cd ..\..

cd Libs\File
call "CleanMe.Bat"
cd ..\..

cd Libs\AnimTime
call "CleanMe.Bat"
cd ..\..

