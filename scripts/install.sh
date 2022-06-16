#!/bin/bash

#====================================================
#     Install Boost.org for Windows
#====================================================
install_windows_boost() {
    mkdir "C:\install"
    cd "C:\install" || exit
    wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.zip
    unzip boost_1_79_0.zip
    rm boost_1_79_0.zip
    cd - || exit
    mkdir "C:\boost-build"
    mkdir "C:\install\boost_1_79_0\boost-build"
    mkdir "C:\boost"
    cd "C:\install\boost_1_79_0\tools\build" || exit
    .\bootstrap.bat gcc
    .\b2 --prefix="C:\boost-build" install
    cd - || exit
    cd "C:\install\boost_1_79_0"  || exit
    b2 --build-dir="C:\install\boost_1_79_0\build" --build-type=complete --prefix="C:\boost" toolset=gcc install
    cd - || exit
}

#====================================================
#     OS-SPECIFIC INFORMATION
#====================================================
UNAME=$(uname)
main="examples"
if [[ "$UNAME" == Darwin* ]] ; then
    INCLUDE=$(pcre-config --cflags)
    LIBRARY=$(pcre-config --libs)
    INCL=${INCLUDE:2}
    LIB=${LIBRARY:2}
elif [[ "$UNAME" == Linux* ]] ; then
    INCL=/usr/include/
    LIB=/usr/lib/
else
	main="${main}.exe"
    INCL="C:\include"
    LIB="C:\lib"
fi

#====================================================
#     INSTALLING PREREQUISITES
#====================================================

# Installing prerequisite packages
echo "Updating and upgrading the system..."
if [[ "$UNAME" == Darwin* ]] ; then
    brew install boost wget unzip gcc make
elif [[ "$UNAME" == Linux* ]] ; then
    sudo apt install build-essential g++ libboost-all-dev wget unzip
else
    choco install wget unzip make
    read -p "Do you want to install and build Boost.org? (y/n) " word__boost
    if [ "$word__boost" == "y" ] || [ "$word__boost" == "Y" ] ; then
        install_windows_boost
    else
        echo "Boost.org will not be installed."
    fi
fi

# Installing ExprTk
if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
    echo ""
    echo "Installing  library..."
    exprtk_sha1=ca5c577917646ddba3f71ce6d5dd7d01f351ee80
    wget https://github.com/ArashPartow/exprtk/archive/$exprtk_sha1.zip
    mv $exprtk_sha1.zip exprtk-$exprtk_sha1.zip
    unzip exprtk-$exprtk_sha1.zip
    sudo cp exprtk-$exprtk_sha1/exprtk.hpp "${INCL}"
    rm -rf exprtk-*
fi
echo ""

# Installing optional packages
read -p "Do you want to install optional arsenalgear prerequisites (y/n)? " word_o
if [ "$word_o" == "y" ] || [ "$word_o" == "Y" ] ; then
    if [[ "$UNAME" == Darwin* ]] ; then
        brew install doctest cppcheck clang-format valgrind
    elif [[ "$UNAME" == Linux* ]] ; then
        sudo apt install doctest-dev valgrind cppcheck clang-format
    else
        wget https://github.com/doctest/doctest/archive/refs/heads/master.zip
        unzip master.zip
        rm master.zip
        mkdir -p "C:\include\doctest"
        cp "doctest-master\doctest\doctest.h" "C:\include\doctest"
        rm -rf doctest-master
    fi
    pip install hurry.filesize termcolor
fi
echo ""

#====================================================
#     COMPILATION OF THE SOURCE CODE
#     (check if doctest is installed)
#====================================================
if [ -f "/usr/include/doctest/doctest.h" ] || [ -f "/usr/local/Cellar/doctest" ] || [ -f "C:\include\doctest" ] ; then
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
if [ "$word" == "y" ] || [ "$word" == "Y" ] ; then
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo echo "Installing arsenalgear header files into ${INCL} folder..."
        sudo mkdir -p "${INCL}"/arsenalgear
        if ! ( sudo cp -r include/* "${INCL}"/arsenalgear ) ; then
            echo "Cannot install the header file into ${INCL} position of the system!"
        fi
        echo "Installing arsenalgear lib into ${LIB} folder..."
        if ! ( sudo cp lib/* "${LIB}" ) ; then
            echo "Cannot install the library into ${LIB} position of the system!"
        fi
    else
        echo "Installing arsenalgear header files into C:\include\folder..."
        mkdir -p "${INCL}\arsenalgear"
        if ! ( cp -r include/* ${INCL}/arsenalgear ) ; then
            echo "Cannot install the header file into ${INCL} position of the system!"
        fi
        echo "Installing arsenalgear lib into ${LIB} folder..."
        if ! ( cp lib/* ${LIB} ) ; then
            echo "Cannot install the library into ${LIB} position of the system!"
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