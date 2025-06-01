@echo off
setlocal


set "SRC_DIR=C:\Users\jossi\Documents\project based learnig\StephUlC++\troll"
set "BUILD_DIR=%SRC_DIR%\build"
set "VCPKG_TOOLCHAIN=C:/vcpkg/scripts/buildsystems/vcpkg.cmake"


rmdir /s /q "%BUILD_DIR%"
mkdir "%BUILD_DIR%"


cmake -S "%SRC_DIR%" -B "%BUILD_DIR%" -G "MinGW Makefiles" ^
  -DCMAKE_TOOLCHAIN_FILE=%VCPKG_TOOLCHAIN% ^
  -DVCPKG_TARGET_TRIPLET=x64-mingw-static ^
  -DCMAKE_BUILD_TYPE=Release

IF ERRORLEVEL 1 (
  echo CMake configuration failed!
  pause
  exit /b
)

cmake --build "%BUILD_DIR%" --config Release

IF ERRORLEVEL 1 (
  echo Build failed!
  pause
  exit /b
)


start "" "%BUILD_DIR%\bin\libtcod-getting-started.exe"
pause
