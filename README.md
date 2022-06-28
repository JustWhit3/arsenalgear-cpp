<p align="center"><img src="https://github.com/JustWhit3/arsenalgear-cpp/blob/main/img/logo.svg" height=220></p>

<h3 align="center">A library containing general purpose utils</h3>
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

- [Constants](https://justwhit3.github.io/arsenalgear-cpp/constants_8hpp.html): contains a list of constants developed for utility.
  - [Null string](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1d792d292bac3e11731eb31cac8dd46e) and [empty space](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#af68907b37ef6e4abe00f6cf74778cde0).
- [Math](https://justwhit3.github.io/arsenalgear-cpp/math_8hpp.html): contains a list of mathematical tools.
  - [roundoff](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a955159eb8ba52ef974bfb4084e1ba45f): function use to round a floating point.
  - [IsInBounds](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1204c90fcc0baef948c5302bb127cc4a): functions used to check if a variable lies in a range.
- [Operators](https://justwhit3.github.io/arsenalgear-cpp/operators_8hpp.html): contains a list of operators redefinition.
  - [Operator * redefinition](https://justwhit3.github.io/arsenalgear-cpp/operators_8hpp.html#aa21cb9291ed5e17a8b54f4538e72aa33) to multiply a string by an object (and vice-versa).
- [Stream](https://justwhit3.github.io/arsenalgear-cpp/stream_8hpp.html): contains a list of input / output stream tools.
  - [null_stream](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a86c4b2752b7974c764df413b76a4f715:~:text=%E2%97%86-,null_stream,-boost%3A%3Aiostreams%3A%3Astream): definition of the null stream.
  - [savebuf](https://justwhit3.github.io/arsenalgear-cpp/classagr_1_1savebuf.html): class used to store the output of an output stream (useful for testing).
- [Utils](https://justwhit3.github.io/arsenalgear-cpp/system_8hpp.html): contains a list of generic utils which don't fit any of the other categories.
  - [Generic utils](https://justwhit3.github.io/arsenalgear-cpp/utils_8hpp.html) are provided here.
- [System](https://justwhit3.github.io/arsenalgear-cpp/utils_8hpp.html): contains a list of generic utils to manage system settings.
  - [getCommandOut](https://justwhit3.github.io/arsenalgear-cpp/namespaceagr.html#a1941ebf177b4bdb1d7f322ed3daed0bc): function used to print the output of a command in the console.

## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->

<!-- ALL-CONTRIBUTORS-LIST:END -->
