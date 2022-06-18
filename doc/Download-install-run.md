# Download and install

## Table of contents

- [Prerequisites](#prerequisites)
  - [Mandatory](#mandatory)
  - [Optional](#optional)
- [Install](#install)
- [Update](#update)
- [Uninstall](#uninstall)
- [Compile and run](#compile-and-run)
  - [Use in your device](#use-in-your-device)
  - [Compile the source code example and testing](#compile-the-source-code-example-and-testing)
- [Other scripts](#other-scripts)
  - [debug_cpp.sh](#debugsh)

## Prerequisites

All the prerequisites can be installed during the first step of the automatic installation with the installer [script](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh).

### Mandatory

Tools:

- C++17 standard.
- g++ compiler (g++ 9.3.0 has been tested so far) for compilation.
- [GNU make](https://www.opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners/#:~:text=Installing%20GNU%20Make,install%20build%2Dessential.) for compilation.

> **NOTE**: if you are on **MacOS** you would need also [Xcode](https://www.freecodecamp.org/news/how-to-download-and-install-xcode/) and [Homebrew](https://brew.sh/index_it) installed.
> **NOTE**: if you are on **Windows** you would need also [pacman](https://www.msys2.org/docs/package-management/) or [chocolately](https://chocolatey.org/) installed.

Libraries and frameworks:

- [Boost](https://www.boost.org/) library.
- [ExprTK](http://www.partow.net/programming/exprtk/) library (no Windows).

### Optional

Tools:

- [Valgrind](https://valgrind.org/) to run the [debug.sh](#debugsh) script.
- [Cppcheck](https://github.com/danmar/cppcheck) to run the [debug.sh](#debugsh) script.
- [Clang formatter](https://stackoverflow.com/questions/20756924/how-can-i-install-clang-format-in-ubuntu#:~:text=16.04%2C%20simply%20do%3A-,sudo%20apt%20install%20clang%2Dformat,-Share) to format the code for pull requests.
- [wget](https://www.techwalla.com/articles/how-to-install-wget-in-ubuntu) for the installer script.
- [unzip](https://www.mysoftkey.com/linux/how-to-do-zip-and-unzip-file-in-ubuntu-linux/) for the installer script.

Libraries and frameworks:

- [doctest](https://github.com/onqtam/doctest) for testing.
- [hurry.filesize](https://pypi.org/project/hurry.filesize/) for `size_of_dir.py` script, used in the installer script.
- [termcolor](https://pypi.org/project/termcolor/) for `size_of_dir.py` script, used in the installer script..

## Install

An installer script, called [install.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh), has been introduced. This script can be used to properly install the library into your computer, in order to easily use it in your programs.

Once the source code has been downloaded you can simply run this script from the root directory of the library:

```shell
./scripts/install.sh
```
> **NOTE**: this script supports the installation on Ubuntu, MacOS and Windows operating systems.

> **NOTE**: if you are on *Cygwin64* you may get an error related to the `\r` character. To solve it run the `dos2unix` command on the script (ex: `dos2unix install.sh`) before running it.

A new library *libarsenalgear.a* (or *libarsenalgear.lib* in the Windows case) will be created into the `/usr/local/lib` folder of your computer and the [*header*](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include) files will be installed into `/usr/local/include`.
> **NOTE**: if you are on MacOS or Windows the paths are slightly different (looks at [install.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh)).

## Update

In case you want to update the source code from the latest improvements of the repository, you can use the updater script, called [update.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/update.sh).

From the repository folder type this command on the shell:

```shell
./scripts/update.sh
```

Then, you can reinstall the cpp source code:

```shell
./scripts/install.sh
```

## Uninstall

In case you want to uninstall the software from your computer, you can use the uninstaller script, called [uninstall.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/uninstall.sh).

From the repository folder type this command on the shell:

```shell
./scripts/uninstall.sh
```

## Compile and run

### Use in your device

Once you have installed the library you can freely use it in one of your C++ projects by including one or more of the modules:

```c++
#include <arsenalgear/module_name.hpp>
```

for example:

```c++
#include <arsenalgear/math.hpp>
```

Now you are able to access al the functions and classes of the library.

You can additionally add also a namespace directive if you want:

```c++
using namespace agr;
```

Supposing you are using the library in a program called *program.cpp*, to compile it you have simply to enter this command in the shell:

```shell
g++ program.cpp -larsenalgear
```

> **NOTE**: if you are on **Windows** and didn't install the headers and libraries in a system standard path you probably need to add also the `-I\path\to\include` and `-L\path\to\lib` flags.

and then you can run the code with:

```shell
./a.out
```
> **NOTE**: executable is called `a.exe` if you are on Windows.


> **NOTE**: at least c++17 standard is required to successfully access al the library features.

### Compile the source code example and testing

The source code contains also an example code [*src/examples.cpp*](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/src/examples.cpp) to show the user a simple usage of all the features supported by the library and test codes in the [**test**](https://github.com/JustWhit3/osmanip/blob/main/cpp/test) folder to test the correct functionality of the library functions and methods.

To compile them I prepared a [Makefile](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/Makefile). The source code is already compiled when you install the library, but in case you don't want to install the package and explore only the library features through this examples, you can run this command on the shell:

```shell
make
```
> **NOTE**: this Makefile is compatible with Ubuntu and MacOS operating systems.

This will compile both main and test codes. An extra **obj** folder with object files and a **bin** folder with two executables, *main* and *tests*, are now created.
>**NOTE**: compilation may be slow due to the expensive operation of the `parsed_f` function, which uses the ExprTK library.

You have simply to run the former in order to run the entire example code:

```shell
./bin/examples
```

or the latter in order to test the correct functionalities of the library classes methods and functions:

```shell
./bin/tests
```

If you want to compile only the main code you can simply enter:

```shell
make examples
```

if instead you want to compile only the tests code you can use the following command:

```shell
make tests
```

There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:

```shell
make clean
```

## Other scripts

Other scripts have been provided into the [**scripts**](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts) folder. After compiling the source code, they can be run from the repository home directory.

### debug_cpp.sh

This script is used to run [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) debugging tools on the whole code.

You can run Valgrind debugging tools with a specific executable:

```shell
./scripts/debug_cpp.sh [valgrind-tool-name] [executable-name]
```
