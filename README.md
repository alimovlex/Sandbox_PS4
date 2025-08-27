# Sample: Sandbox

![Human Coded](https://img.shields.io/badge/human-coded-brightgreen?logo=data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSIyNCIgaGVpZ2h0PSIyNCIgdmlld0JveD0iMCAwIDI0IDI0IiBmaWxsPSJub25lIiBzdHJva2U9IiNmZmZmZmYiIHN0cm9rZS13aWR0aD0iMiIgc3Ryb2tlLWxpbmVjYXA9InJvdW5kIiBzdHJva2UtbGluZWpvaW49InJvdW5kIiBjbGFzcz0ibHVjaWRlIGx1Y2lkZS1wZXJzb24tc3RhbmRpbmctaWNvbiBsdWNpZGUtcGVyc29uLXN0YW5kaW5nIj48Y2lyY2xlIGN4PSIxMiIgY3k9IjUiIHI9IjEiLz48cGF0aCBkPSJtOSAyMCAzLTYgMyA2Ii8+PHBhdGggZD0ibTYgOCA2IDIgNi0yIi8+PHBhdGggZD0iTTEyIDEwdjQiLz48L3N2Zz4=)

This project contains example code for initializing the SceVideoOut library, and for CPU rendering text on the screen with an arial font. A screenshot from the running application can be seen below.

- **Title ID**: BREW00085
- **Content ID**: IV0000-BREW00085_00-NETWORKKEX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/sandbox
|-- assets
    |-- fonts
        |-- Gontserrat-Regular.ttf  // Font truetype file
        |-- OFL.txt                 // Font license
|-- font    
    |-- x64
        |-- Debug                   // Object files / intermediate directory
    |-- build.bat                   // Batch file for building on Windows
    |-- sandbox.vcxproj                // Visual studio project files
    |-- sandbox.vcxproj.filters
    |-- sandbox.cvxproj.user
    |-- text_drawer.cpp                // Source code interfacing with SceVideoOut graphics
    |-- text_drawer.hpp                  // Header file for graphics helper functions
    |-- tcp_server.cpp                // Source code interfacing with tcp socket networking
    |-- tcp_server.hpp                  // Header file for networking helper functions
    |-- main.cpp                    // main source file
|-- sce_module                      // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                         // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                       // final eboot (not present until built)
|-- font.sln                        // Visual studio solution file
|-- Makefile                        // Make rules for building on Linux
|-- pkg.gp4                         // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut
- libSceSysmodule
- libSceFreeType
- lSceUserService


## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "hello_world" "%OO_PS4_TOOLCHAIN%\\samples\\hello_world"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
- Crazyvoid "added text wrapping"
- alimovlex "Mixed sample projects and made it Sandboxed"
