cd /d %~dp0

if not exist googletest (
    git submodule init
    git submodule update
)

set DIR0=build-off
set DIR1=build-on

if exist %DIR0% rmdir /s /q %DIR0%
if exist %DIR1% rmdir /s /q %DIR1%
mkdir %DIR0%
mkdir %DIR1%

cmake -D BUILD_SHARED_LIBS=0 -B%DIR0% -H. || exit /b 1
cmake -D BUILD_SHARED_LIBS=1 -B%DIR1% -H. || exit /b 1

cmake --build %DIR0%  --config Debug   || exit /b 1
cmake --build %DIR1%  --config Debug   || exit /b 1
cmake --build %DIR0%  --config Release || exit /b 1
cmake --build %DIR1%  --config Release || exit /b 1

exit /b 0