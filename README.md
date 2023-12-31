# QtCalculator

This is a simple calculator to learn qt

## Installing Qt

- Go to [the Qt OSS download page](https://www.qt.io/download-qt-installer-oss/) and select your platform
- Sign up or sign in and follow the installation steps for a default installation
- Once done, open the Qt Maintenance Tool, select Add or remove components and check Qt 6.6.1
- Click next, agree to the license and finish the installation

## Building and running (Linux/Unix)

Clone the git repository

```sh
git clone https://github.com/tygoee/tygoee
```

Prepare the build

```sh
cmake . -DCMAKE_PREFIX_PATH=~/Qt/6.6.1/gcc_64 -B ./build
```

Build the program

```sh
~/Qt/Tools/CMake/bin/cmake --build ./build --target all
```

Run your build

```sh
./build/qtcalculator
```
