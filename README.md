<p align="center"><img src="https://github.com/JustWhit3/arsenalgear-cpp/blob/main/img/logo.svg" height=220></p>

<h3 align="center">A library containing general purpose utils I developed for other projects</h3>
<p align="center">
  <img title="v1.0" alt="v1.0" src="https://img.shields.io/badge/version-v1.0-informational?style=flat-square">
  <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square"></br>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/arsenalgear-cpp?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/arsenalgear-cpp?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/arsenalgear-cpp?color=red"></br>
  <img title="v1.0" alt="v1.0" src="https://github.com/JustWhit3/arsenalgear-cpp/actions/workflows/codeql-analysis.yml/badge.svg">

***

## Table of contents

- [Introduction](#introduction)
- [Supported operating systems](#supported-operating-systems)
- [Documentation](#documentation)
- [News from the last release](#news-from-the-last-release)
- [List of features](#list-of-features)
- [Credits](#credits)
  - [Project leaders](#project-leaders)

## Introduction

This library contains a set of generic utils I developed for other projects. There are several sub-headers / modules related to the various topics (math, iostream and others). You can easily install the library using one of the installation scripts of the [scripts](https://github.com/JustWhit3/arsenalgear-cpp/tree/main/scripts) folder and run an example code.

Existing tools are constantly updated and new ones are added once their development is required for other projects.

Some projects in which I am using this library are, for example: [osmanip](https://github.com/JustWhit3/osmanip) and [SAFD-algorithm](https://github.com/JustWhit3/SAFD-algorithm).

If you want to use this library please cite it following [this](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/CITATION.cff) citation template.

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

## Supported operating systems

- **Linux**
  - *Ubuntu* (tested)
- **Windows**
  - *Cygwin64* (tested)
  - *MSYS2* (tested)
  - *MinGW* (tested)
  - *WSL* (tested)
- **MacOS**

## Documentation

Repository diagram structure:

```txt
arsenalgear/
├── .github/
│   ├── workflows/
│   │   ├── codeql-analysis.yml
│   │   ├── DocGenerator.yml
├── doc/
│   ├── Code structure.md
│   ├── Download-install-run.md
├── include/
│   ├── constants.hpp
│   ├── math.hpp
│   ├── operators.hpp
│   ├── stream.hpp
│   ├── utils.hpp
├── src/
│   ├── examples.cpp
│   ├── operators.cpp
│   ├── stream.cpp
├── test/
│   ├── tests_math.cpp
│   ├── tests_operators.cpp
│   ├── tests_stream.cpp
│   ├── tests_utils.cpp
├── scripts/
│   ├── install.sh
│   ├── uninstall.sh
│   ├── debug.sh
│   ├── update.sh
│   ├── size_of_dir.py
├── img/
├── Makefile
├── Doxyfile
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── CITATION.cff
├── .gitignore
├── .all-contributorsrc
├── .clang-format
├── .valgrindrc
```

General documentation:

- [Contributing to the repository](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Contributing.md): a generic file containing detailed info about how to open an issue or send a pull request to contribute.
- [Code structure](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Code%20structure.md): contains a detailed list of the `cpp` objects of the repository and how to use them.
- [Download, install and run](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Download%2C%20install%20and%20run.md): contains instructions about how to install, download and run the repository code and extra information about the scripts of the [scripts](https://github.com/JustWhit3/arsenalgear-cpp/tree/main/scripts) folder.

## News from the last release

- Added full support to Windows operating systems.
- Added full support to MacOS operating systems.
- Added Doxygen documentation.

## List of features

Here you can find the list of features implemented in the current version of the library:

- [Constants](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/constants.hpp): contains a list of constants developed for utility.
- [Math](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/math.hpp): contains a list of mathematical tools.
- [Operators](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/operators.hpp): contains a list of operators redefinition.
- [Stream](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/stream.hpp): contains a list of input / output stream tools.
- [Utils](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/utils.hpp): contains a list of generic utils which don't fit any of the other categories.

## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->

<!-- ALL-CONTRIBUTORS-LIST:END -->
