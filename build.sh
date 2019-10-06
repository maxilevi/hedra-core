rm -r -dir --force ./cmake-build-x64/
mkdir ./cmake-build-x64/
cmake -S . -B ./cmake-build-x64/ -A x64
cmake --build ./cmake-build-x64/ -- -property:Configuration=Release

rm -r -dir --force ./cmake-build-x32/
mkdir ./cmake-build-x32/
cmake -S . -B ./cmake-build-x32/ -A Win32
cmake --build ./cmake-build-x32/ -- -property:Configuration=Release