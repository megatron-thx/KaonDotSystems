# KaonDotSystems
Generate Diagrams that can open documents

# Megatron set

``` bash
cd /path/to/your/repo
git config --local user.name "megatron.thx"
git config --local user.email "megatron.thx@proton.me"

# main -> master
git branch -M master
git remote set-url origin git@github-megatron:megatron-thx/KaonDotSystems.git
git push -u origin master
git pull
git push
```

## 🔧 Fix: Change Default Branch on GitHub (Web Interface)

    Go to your repo on GitHub: https://github.com/megatron-thx/KaonDotSystems
    Click Settings → Branches
    Under "Default branch", click the edit icon (pencil)
    Change from main to master
    Confirm the change


``` bash
git push origin --delete main
git fetch --prune
git branch -r
git push
git pull
```

# First Concept

Hello world

## Dependencies

### Cmake

``` bash
mkdir -p /d/bin/cmake/
curl -L -o cmake-4.3.1-windows-x86_64.zip \
    https://github.com/Kitware/CMake/releases/download/v4.3.1/cmake-4.3.1-windows-x86_64.zip
unzip cmake-4.3.1-windows-x86_64.zip -d /d/bin/cmake/

# ~/.bashrc
export PATH=$PATH:/d/bin/cmake/cmake-4.3.1-windows-x86_64/bin

source ~/.bashrc
cmake --version
```


``` bash
# git bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg.exe search qt
#./vcpkg.exe install qtbase
./vcpkg.exe install qtbase:x64-windows
./vcpkg.exe install qtbase:x64-windows --debug
cd ..

cd qt_uml_test/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
#cmake --build build
cmake --build build --config Release

../vcpkg/installed/x64-windows/tools/Qt6/bin/windeployqt.exe build/Release/qt_uml_test.exe
./build/Release/qt_uml_test.exe

# this part does not work
cmake --build build --config Debug
../vcpkg/installed/x64-windows/tools/Qt6/bin/windeployqt.exe build/Debug/qt_uml_test.exe

./build/Debug/qt_uml_test.exe
```


