@echo off

:: Define color codes for Windows
set "GREEN=" 33[0;32m""
set "RED=" 33[0;31m""
set "NC=" 33[0m""

:: Check if the build directory exists
if not exist "build" (
    echo %GREEN%Creating build directory...%NC%
    mkdir build
) else (
    echo %GREEN%Build directory already exists.%NC%
)

:: Move into the build directory
cd build || exit /b

:: Run cmake, make, and ctest
echo %GREEN%Running cmake...%NC%
cmake ..
if errorlevel 1 (
    echo %RED%CMake configuration failed. Exiting.%NC%
    exit /b 1
)

echo %GREEN%Running make...%NC%
make
if errorlevel 1 (
    echo %RED%Build process failed. Exiting.%NC%
    exit /b 1
)

echo %GREEN%Running tests...%NC%
ctest -V
if errorlevel 1 (
    echo %RED%Tests failed. Exiting.%NC%
    exit /b 1
)

echo %GREEN%Build and tests completed successfully.%NC%
