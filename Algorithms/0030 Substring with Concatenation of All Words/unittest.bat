@echo off

for /f "tokens=*" %%i in ('%SystemRoot%\System32\where.exe git') do set GIT=%%i

if not exist %GIT% (
	echo Can't find %GIT%
	goto :ExitBatch
)

set GIT=D:\Git\mingw64\bin\git.exe

for /f "tokens=*" %%i in ('%GIT% rev-parse --show-toplevel') do set REPOSITORY_ROOT=%%i

set GOOGLE_TEST_PATH=%REPOSITORY_ROOT%/Third_Party/googletest
set GOOGLE_TEST_INCLUDE=%GOOGLE_TEST_PATH%/googletest/include
set GOOGLE_TEST_LIB=%GOOGLE_TEST_PATH%/build/lib/Release/gtest.lib
set GOOGLE_MOCK_INCLUDE=%GOOGLE_TEST_PATH%/googlemock/include
set VSWHERE="%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist %VSWHERE% (
	echo Can't find %VSWHERE%
	goto :ExitBatch
)

for /f "tokens=*" %%i in ('%VSWHERE% -property installationPath') do set VSROOT=%%i

set VCVARS64="%VSROOT%\VC\Auxiliary\Build\vcvars64.bat"

if not exist %VCVARS64% (
	echo Can't find %VCVARS64%
	goto :ExitBatch
)

@rem set up the environment
call %VCVARS64%

@rem compile
cl.exe /EHsc /MT /Od /I%GOOGLE_TEST_INCLUDE% /I%GOOGLE_MOCK_INCLUDE% unittest.cc solution.c common.c %GOOGLE_TEST_LIB%

echo %~nx0 is complete successfully
@rem pause
exit /b 0

:ExitBatch
echo Terminate %~nx0 batch
exit /b 1