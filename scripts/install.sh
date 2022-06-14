#!/bin/bash

#====================================================
#     OS-SPECIFIC INFORMATION
#====================================================
UNAME=$(uname)
main="examples"
if [[ "$UNAME" == CYGWIN* || "$UNAME" == MINGW* ]] ; then
	main="${main}.exe"
elif [[ "$UNAME" == Darwin* ]] ; then
    INCLUDE=$(pcre-config --cflags)
    LIB=$(pcre-config --libs)
fi

#====================================================
#     INSTALLING PREREQUISITES
#====================================================
echo "Updating and upgrading the system..."
if [[ "$UNAME" == Darwin* ]] ; then
    brew install boost wget unzip gcc make
else
    sudo apt install build-essential g++ libboost-all-dev wget unzip
fi
echo ""
echo "Installing ExprTk library..."
exprtk_sha1=ca5c577917646ddba3f71ce6d5dd7d01f351ee80
wget https://github.com/ArashPartow/exprtk/archive/$exprtk_sha1.zip
mv $exprtk_sha1.zip exprtk-$exprtk_sha1.zip
unzip exprtk-$exprtk_sha1.zip
if [[ "$UNAME" == Darwin* ]] ; then
    sudo cp exprtk-$exprtk_sha1/exprtk.hpp "${INCLUDE:2}"
else
    sudo cp exprtk-$exprtk_sha1/exprtk.hpp /usr/include/
fi
rm -rf exprtk-*
echo ""
read -p "Do you want to install optional arsenalgear prerequisites (y/n)? " word_o
if [ $word_o == "y" ] || [ $word_o == "Y" ] ; then
    if [[ "$UNAME" == Darwin* ]] ; then
        brew install doctest cppcheck clang-format valgrind
    else
        sudo apt install doctest-dev valgrind cppcheck clang-format
    fi
    pip install hurry.filesize termcolor
fi
echo ""

#====================================================
#     COMPILATION OF THE SOURCE CODE
#     (check if doctest is installed)
#====================================================
if [ -f "/usr/include/doctest.h" ] || [ -f "/usr/include/doctest/doctest.h" ] || [ -f "/usr/local/Cellar/doctest" ] ; then
    echo "Compiling the whole arsenalgear code..."
    if ! make ; then
        echo "Compilation failed!"
        exit
    fi
else
    echo "Doctest is not installed, cannot compile the test codes!"
    echo "Compiling only the main code of arsenalgear (this is not a problem for the installation)..."
    if ! make $main ; then
        echo "Compilation failed!"
        exit
    fi
fi
echo ""

#====================================================
#     SAVING FILES INTO THE SYSTEM
#====================================================
./scripts/size_of_dir.py --paths="include lib" --message="on"
echo ""
read -p "Would you like to continue (y/n)? " word
if [ $word == "y" ] || [ $word == "Y" ] ; then
    sudo echo "Installing arsenalgear header files into /usr/local/include folder..."
    if [[ "$UNAME" == Darwin* ]] ; then
        sudo echo "Installing arsenalgear header files into ${INCLUDE:2} folder..."
        sudo mkdir -p "${INCLUDE:2}"/arsenalgear
        if ! ( sudo cp -r include/* "${INCLUDE:2}"/arsenalgear ) ; then
            echo "Cannot install the header file into ${INCLUDE:2} position of the system!"
        fi
        echo "Installing arsenalgear lib into ${LIB:2} folder..."
        if ! ( sudo cp lib/* "${LIB:2}" ) ; then
            echo "Cannot install the library into ${LIB:2} position of the system!"
        fi
    else
        sudo echo "Installing arsenalgear header files into /usr/local/include folder..."
        sudo mkdir -p /usr/local/include/arsenalgear
        if ! ( sudo cp -r include/* /usr/local/include/arsenalgear ) ; then
            echo "Cannot install the header file into /usr/local/include position of the system!"
        fi
        echo "Installing arsenalgear lib into /usr/local/lib folder..."
        if ! ( sudo cp lib/* /usr/local/lib ) ; then
            echo "Cannot install the library into /usr/local/lib position of the system!"
        fi
    fi
else
    echo "Installation has been canceled!"
    exit
fi
echo ""

#====================================================
#     INSTALLATION COMPLETED
#====================================================
echo "Arsenalgear has been succesfully installed!"
echo ""
echo "To compile any C++ program with this library, use:"
echo ""
echo "           g++ program.cpp -larsenalgear"
echo ""
echo "If you use a library component which uses threads:"
echo ""
echo "           g++ program.cpp -larsenalgear -pthread"
echo ""
echo "Enjoy! :)"
echo ""