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
- [Supported operating systems](#supported-operating-systems)
- [Documentation](#documentation)
- [News from the latest release](#news-from-the-last-release)
- [List of features](#list-of-features)
  - [Constants](#constants)
  - [Math](#math)
  - [Operators](#operators)
  - [Stream](#stream)
  - [System](#system)
  - [Utils](#utils)
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

General documentation:

- [Contributing to the repository](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Contributing.md): a generic file containing detailed info about how to open an issue or send a pull request to contribute.
- [Download, install and run](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Download-install-run.md): contains instructions about how to install, download and run the repository code and extra information about the scripts of the [scripts](https://github.com/JustWhit3/arsenalgear-cpp/tree/main/scripts) folder.
- [Repository structure](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/doc/Repository-structure.md): detailed repository diagram structure.

**Code documentation** is generated using [*Doxygen*](https://www.doxygen.nl/manual/starting.html) and can be accessed [here](https://justwhit3.github.io/arsenalgear-cpp/).

## News from the latest release

- Added a new [stream](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/stream.hpp) class.
- Added [system](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/system.hpp) utils.
- Added full support to Windows operating systems.
- Added full support to MacOS operating systems.
- Added Doxygen documentation.

## List of features

Here you can find the list of features implemented in the current version of the library:

### Constants

- [Null string](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1d792d292bac3e11731eb31cac8dd46e): template variable to define the null string.
- [empty space](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#af68907b37ef6e4abe00f6cf74778cde0): template variable to define the empty space.

### Math

- [roundoff](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a955159eb8ba52ef974bfb4084e1ba45f): function use to round the value a floating point variable.
- [IsInBounds](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1204c90fcc0baef948c5302bb127cc4a): functions used to check if a variable lies in a range.
- [parsed_f](https://github.com/JustWhit3/arsenalgear-cpp/blob/main/include/math.hpp#:~:text=*/-,template%20%3Ctypename%20T%3E,-inline%20double%20parsed_f): functions used to parse a mathematical function.

### Operators

- [Operator * redefinition](https://justwhit3.github.io/arsenalgear-cpp/operators_8hpp.html#aa21cb9291ed5e17a8b54f4538e72aa33) to multiply a string by an object (and vice-versa), in the sense that the string is repeated n-times.

### Stream

- [null_stream](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a86c4b2752b7974c764df413b76a4f715:~:text=%E2%97%86-,null_stream,-boost%3A%3Aiostreams%3A%3Astream): definition of the null stream.
- [savebuf](https://justwhit3.github.io/arsenalgear-cpp/classagr_1_1savebuf.html): class used to store the output of an output stream (useful for testing).

### System

- [getCommandOut](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1941ebf177b4bdb1d7f322ed3daed0bc): function used to print the output of a command in the console.

### Utils

- [multi](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a523bed79d63264512bfc2a9b12027c90): function used to multiply a string for n times.
- [split_string](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#aeccaa1589b9a22ee3ad2bc2ac798dbcd): function used to split a string based on a certain reges.
- [maxptr](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a400b1e2872ab3a6c7166c9fc4ecfb157): function used to find the maximum value of a generic pointer.
- [except_error_func](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a4985365fab7e1937492277a49ee3cb2f:~:text=%E2%97%86-,except_error_func,-()): function used to throw customized exception error.
- [isFloatingPoint](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a30f754b298e55c68819829df78d936cb): function used to check if an expression is a floating point or not.
- [one](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a79c1d16a030bfa822fcf06fcfd56db5a): function used to find the incremented unit of a loop.


## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->

<!-- ALL-CONTRIBUTORS-LIST:END -->
