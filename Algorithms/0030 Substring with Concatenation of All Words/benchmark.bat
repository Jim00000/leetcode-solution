@echo off

for /f "tokens=*" %%i in ('%SystemRoot%\System32\where.exe git') do set GIT=%%i

if not exist %GIT% (
	echo Can't find %GIT%
	goto :ExitBatch
)

set GIT=D:\Git\mingw64\bin\git.exe

for /f "tokens=*" %%i in ('%GIT% rev-parse --show-toplevel') do set REPOSITORY_ROOT=%%i

set GOOGLE_BENCHMARK_PATH=%REPOSITORY_ROOT%/Third_Party/benchmark
set GOOGLE_BENCHMARK_INCLUDE=%GOOGLE_BENCHMARK_PATH%/include
set GOOGLE_BENCHMARK_LIB=%GOOGLE_BENCHMARK_PATH%/build/src/Release/benchmark.lib
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
cl.exe /EHsc /MD /Od /I%GOOGLE_BENCHMARK_INCLUDE% benchmark.cc solution.c common.c %GOOGLE_BENCHMARK_LIB%

echo %~nx0 is complete successfully
@rem pause
exit /b 0

:ExitBatch
echo Terminate %~nx0 batch
exit /b 1