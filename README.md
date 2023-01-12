# opengl

## Prerequisites

First of all, you need to install Visual Studio (here, we are using 2022 CE)
Next, you also need to check you have the latest drivers for your graphics card.

Then, you need to install CMake (here, the `3.25.1` version is used), GLFW source package (`v3.3.8` here), and generate a Glad file with the appropriate gl version API and set the `Core` in the profile option.

## Setup workspace

Create a C++ empty project on VS Studio and create a folder in the project: `Librairies`. Then, add two other new folders in `Librairies`, named `include` and `lib`.


## Generate GLFW
Extract the `glfw.zip` downloaded file and open CMake. Browse the `glfw path source` and create a folder named `build` in your glfw file. Then, specify the build folder in the "Build Browse" option.

Click on the `Configure` option, and click on finish. Check if you have the following options actived: 
```
GLWF_BUILD_DOCS
GLWF_EXAMPLES
GLWF_TESTS
GLWF_INSTALL
USE_MSVC_RUNTIME_LIBRARY_DLL 
```
Click on `Configure` again, then `Generate`.
Once everything is done, exit from CMake.

## Build GLFW
Run `GLFW.sln` and build the solution. If you have errors, you need to regenerate GLFW using Cmake.
Once the build is finish, exit VS Studio.

Open the GLFW extracted folder, check the `src>Debug>` path for the `glfw3.lib` file, and copy paste in your `lib` project folder.
Back to the extracted folder, go to `include` and copy paste the `GLFW` folder in your `include` project folder.

Go to the `glad` folder, and copy paste the `include` contents in your `include` project folder, then extract the `glad.c` file to your main project.

## Configure VS Studio librairies access

Go to the project properties, check the platform option are correcly set to `All platforms`, then in the `VC++ Directories`, edit the `Include Directory` path to yours. Same for the `Library Directories`.
Then, in the `Linker` and `Input` section, add `glfw3.lib` and `opengl32.lib` in your additionnal dependencies options.

Now, the last step is to drag the `glut.c` to your VS Studio source files.

## Test the correct installation and workspace

Create a Main.cpp file in your source files. Include these files:
```
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
```

create a main fonction, make it returns an int and run Windows Local Debugger. If you have no error, then the installation was successfully completed.
