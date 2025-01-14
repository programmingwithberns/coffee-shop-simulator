# How to run the program

## Prerequisites
- Compiler that can compile C++17 code (For windows users, see [MSYS2](https://www.msys2.org/))
- CMake version 3.5+ (see [CMake Download](https://cmake.org/download/))
- Installed Catch2 (see [Installing Catch2 from git](https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#installing-catch2-from-git-repository))
- Basic knowledge of terminal (see [This tutorial](https://www.youtube.com/watch?v=HcYAThNq0H8))
- Git installed ([Installing Gitbash for windows](https://www.youtube.com/watch?v=jZj0jaDKBXU))

## Steps
1. Clone the repository
```shell
git clone https://github.com/programmingwithberns/coffee-shop-simulator.git coffee-shop
```

If you are lazy like me, just do or follow steps 2 - 4 below 
```shell 
cd coffee-shop && ./run.sh # for unix systems or # cd coffee-shop && ./run.cmd # for windows
```

2. Move into the cloned repository
```shell 
cd coffee-shop 
```

3. Compile the project and run it
```shell
# Create the build directory and move into it 
mkdir build && cd build
```
```shell
# let cmake build the project for your platform
cmake .. && make
```
```shell 
# run the app. 
./app # ./app.exe for windows
```

4. Run the tests
```shell 
ctest -V # -V for verbosity
```