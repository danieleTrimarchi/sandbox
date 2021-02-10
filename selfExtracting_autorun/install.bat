ECHO OFF
echo.> outputInstallFile.txt
echo %date% >> outputInstallFile.txt
echo "Install.bat was launched!" >> outputInstallFile.txt

rem https://stackoverflow.com/a/7505752/15176458
FOR /F "usebackq tokens=3 " %%i in (`REG QUERY "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders" /v Desktop`) DO SET DESKTOPDIR=%%i 
FOR /F "usebackq delims=" %%i in (`ECHO %DESKTOPDIR%`) DO SET DESKTOPDIR=%%i 
rem Remove spaces in variable : https://stackoverflow.com/a/30897103/15176458
set DESKTOPDIR=%DESKTOPDIR: =%

rem create a shortcut to Release/bin/Platform.exe to the Desktop 
mklink %DESKTOPDIR%\icoStudio_0_1_2.exe Viewer_P_beta-0.1.2_Release_embedded_client_8acb199c34a5a0ebee86e50c46f9e466\Release\bin\Platform.exe

call vcredist_x64.exe 
echo "Visual Studio Runtime installer executed ! " >> outputInstallFile.txt

call MATLAB_Runtime_R2020a_Update_5_win64\setup.exe
echo "Matlab installer executed ! " >> outputInstallFile.txt

cls
color 0C
set /p DUMMY=Please hit a key to continue when Matlab has finished...

rem Set the patsh for the deployGUI 
echo.> savePaths.xml
echo ^<data^> >> savePaths.xml
echo ^<items^> >> savePaths.xml
echo ^<item name="matlabReq"^>/home^</item^> >> savePaths.xml 
echo ^<item name="vs"^>C:/Users/danie/OneDrive/Bureau/VCRuntime^</item^> >> savePaths.xml
echo ^<item name="matlab_R2019b"^>C:\Program Files\MATLAB\MATLAB Runtime\v97\runtime\win64^</item^> >> savePaths.xml
echo ^<item name="matlab_R2020a"^>C:\Program Files\MATLAB\MATLAB Runtime\v98\runtime\win64^</item^> >> savePaths.xml
echo ^<item name="product"^>Viewer_P_beta-0.1.2_Release_embedded_client_8acb199c34a5a0ebee86e50c46f9e466/Release^</item^> >> savePaths.xml
echo ^</items^> >> savePaths.xml
echo ^</data^> >> savePaths.xml

echo "Launching the DeployGUI ! " >> outputInstallFile.txt
call DeployGUI_daae6df85475fc93a35caef261e551dae4abc2d4\DeployGUI\DeployGUI.exe

:END
