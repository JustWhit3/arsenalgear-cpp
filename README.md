<p align="center"><img src="https://github.com/JustWhit3/arsenalgear-cpp/blob/main/img/logo.svg" height=220></p>

<h3 align="center">A library containing general purpose C++ utils</h3>
<p align="center">
  <img title="v1.2" alt="v1.2" src="https://img.shields.io/badge/version-v1.2-informational?style=flat-square">
  <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square"></br>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/arsenalgear-cpp?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/arsenalgear-cpp?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/arsenalgear-cpp?color=red"></br>
  <img title="codeq" alt="codeq" src="https://github.com/JustWhit3/arsenalgear-cpp/actions/workflows/codeql-analysis.yml/badge.svg">
  <img title="docgen" alt="docgen" src="https://github.com/JustWhit3/arsenalgear-cpp/actions/workflows/DocGenerator.yml/badge.svg">

***

## Table of contents

- [Introduction](#introduction)
- [Install and use](#install-and-use)
  - [Install](#install)
  - [Use in your device](#use-in-your-device)
  - [Compile examples and tests](#compile-examples-and-tests)
- [List of features](#list-of-features)
  - [Constants](#constants)
  - [Math](#math)
  - [Operators](#operators)
  - [Stream](#stream)
  - [System](#system)
  - [Utils](#utils)
  - [Containers](#containers)
  - [Type](#type)
- [Useful scripts](#useful-scripts)
- [Credits](#credits)
  - [Project leaders](#project-leaders)

## Introduction

This library contains a set of generic utils I developed for other projects. There are several sub-headers / modules related to the various topics (math, iostream and others). Existing tools are constantly updated and new ones are added once their development is required for other projects. Some projects in which I am using this library are, for example: [osmanip](https://github.com/JustWhit3/osmanip) and [SAFD-algorithm](https://github.com/JustWhit3/SAFD-algorithm).

If you want to use this library please cite it following [this](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/CITATION.cff) citation template.

If you want to contribute to the repository, see [this](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/CONTRIBUTING.md) document before.

**Code documentation** is generated using [*Doxygen*](https://www.doxygen.nl/manual/starting.html) and can be accessed [here](https://justwhit3.github.io/arsenalgear-cpp/).

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

Supported operating systems:

- **Linux**
  - *Ubuntu* (tested)
- **Windows**
  - *Cygwin64* (tested)
  - *MSYS2* (tested)
  - *MinGW* (tested)
  - *WSL* (tested)
- **MacOS**

## Install and use

### Install

Steps to be reproduced:

**1)** Download one of the releases of the repository.

**2)** Unzip and enter the downloaded repository directory.

**3)** Install and compile the library and its prerequisites

```bash
./script/install.sh
```

> **NOTE**: if you are on *Cygwin64* you may get an error related to the `\r` character. To solve it run the `dos2unix` command on the script (ex: `dos2unix install.sh`) before running it.

A new library *libarsenalgear.a* (or *libarsenalgear.lib* in the Windows case) will be created into the `/usr/local/lib` folder of your computer and the [*header*](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include) files will be installed into `/usr/local/include`.
> **NOTE**: if you are on MacOS or Windows the paths are slightly different (looks at [install.sh](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts/install.sh)).

Prerequisites list:

- A `g++` compiler.
- C++17 standard.
- [GNU make](https://www.opensourceforu.com/2012/06/gnu-make-in-detail-for-beginners/#:~:text=Installing%20GNU%20Make,install%20build%2Dessential.) for compilation.

**4)** EXTRA: update the repository if needed

```shell
./scripts/update.sh
./scripts/install.sh
```

**5)** EXTRA: uninstall the repository if needed

```shell
./scripts/uninstall.sh
```

### Use in your device

Once you have installed the library you can freely use it in one of your C++ projects by including one or more of the modules:

```c++
#include <arsenalgear/module_name.hpp>
```

To compile it you have simply add the `-larsenalgear` compilation flag.

> **NOTE**: if you are on **Windows** and didn't install the headers and libraries in a system standard path you probably need to add also the `-I\path\to\include` and `-L\path\to\lib` flags.

### Compile examples and tests

To compile examples

```shell
make main
```

>**NOTE**: compilation may be slow due to the expensive operation of the `parsed_f` function, which uses the ExprTK library.

To run all examples:

```shell
./bin/math
./bin/operators
./bin/stream
./bin/system
./bin/tests
./bin/utils
./bin/containers
./bin/type
```

> **NOTE**: executables end with `.exe` if you are on Windows of course.

To compile tests:

```shell
make tests
```

To run tests:

```shell
./bin/tests
```

There is also an option to go back to the pre-compilation state of the code, to do this simply type this command:

```shell
make clean
```

## List of features

### Constants

- [`null_string`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1d792d292bac3e11731eb31cac8dd46e): template variable to define the null string.
- [`empty_space`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#af68907b37ef6e4abe00f6cf74778cde0): template variable to define the empty space.

### Math

- [`roundoff`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a955159eb8ba52ef974bfb4084e1ba45f): function use to round the value a floating point variable.
- [`IsInBounds`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1204c90fcc0baef948c5302bb127cc4a): functions used to check if a variable lies in a range.
- [`parsed_f`](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/math.hpp#:~:text=*/-,template%20%3Ctypename%20T%3E,-inline%20double%20parsed_f): functions used to parse a mathematical function.

### Operators

- [`Operator *` (`int` and string-like object)](https://justwhit3.github.io/arsenalgear-cpp/operators_8hpp.html#aa21cb9291ed5e17a8b54f4538e72aa33) to multiply a string by an integer (and vice-versa), in the sense that the string is repeated n-times.

### Stream

- [`null_stream`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a86c4b2752b7974c764df413b76a4f715:~:text=%E2%97%86-,null_stream,-boost%3A%3Aiostreams%3A%3Astream): definition of the null stream.
- [`savebuf`](https://justwhit3.github.io/arsenalgear-cpp/classagr_1_1savebuf.html): class used to store the output of an output stream (useful for testing).

### System

- [`getCommandOut`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1941ebf177b4bdb1d7f322ed3daed0bc): function used to print the output of a command in the console.

### Utils

- [`multi`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a523bed79d63264512bfc2a9b12027c90): function used to multiply a string for n times.
- [`split_string`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#aeccaa1589b9a22ee3ad2bc2ac798dbcd): function used to split a string based on a certain reges.
- [`maxptr`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a400b1e2872ab3a6c7166c9fc4ecfb157): function used to find the maximum value of a generic pointer.
- [`except_error_func`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a4985365fab7e1937492277a49ee3cb2f:~:text=%E2%97%86-,except_error_func,-()): function used to throw customized exception error.
- [`isFloatingPoint`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a30f754b298e55c68819829df78d936cb): function used to check if an expression is a floating point or not.
- [`one`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a79c1d16a030bfa822fcf06fcfd56db5a): function used to find the incremented unit of a loop.
- [`StringConverter`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1d3019dd5d7deec3df2a2c4e01b89f47): function used to convert a `char` string into other char types (`wchar_t`, `char16_t`, etc...).

### Containers

- [`extract_map_elem`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a70373a18f780e358537a4c57b8ab81aa): function used to extract a vector of elements from a map.
- [`extract_map_keys`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#abe08b78ae648a1b2401c7559de314989): function used to extract a vector of keys from a map.

### Type

- [`is_pointer_to_const_char`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a7c5ec6c4708748caba50bd7444a8707a): function used to check if a string is a pointer to const char.
- [`is_str`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a8cedbda93e6317c38b992056458ba03c): function used to check if a string is an `std::string` object.
- [`is_streamable`](https://justwhit3.github.io/arsenalgear-cpp/structagr_1_1is__streamable.html): struct used to check if a type is streamable to a stream or not.
- [`is_any`](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a962b9e5500ec34ba186b3ad88114a677): function used to check if a type is in a list or not. Very useful to perform this operation with parameter packs.

## Useful scripts

Other scripts have been provided into the [**scripts**](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/scripts) folder. After compiling the source code, they can be run from the repository home directory.

The `debug_cpp.sh` script is used to run [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) debugging tools on the whole code.

You can run Valgrind debugging tools with a specific executable:

```shell
./scripts/debug_cpp.sh [valgrind-tool-name] [executable-name]
```

## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->

<!-- ALL-CONTRIBUTORS-LIST:END -->
