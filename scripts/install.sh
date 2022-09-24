#!/bin/bash

#====================================================
#     OS-SPECIFIC INFORMATION
#====================================================
UNAME=$(uname)
main="examples"
if [[ "$UNAME" == Darwin* ]] ; then
    INCL=/usr/local/include
    LIB=/usr/local/lib
elif [[ "$UNAME" == Linux* ]] ; then
    INCL=/usr/include
    LIB=/usr/lib
else
    read -p "Insert the system include path in which you want to install arsenalgear and its dependencies headers: " word_include
        mkdir -p ${word_include}
        INCL=${word_include}
    read -p "Insert the system lib path in which you want to install arsenalgear and its dependencies static libraries: " word_lib
        mkdir -p ${word_lib}
        LIB=${word_lib}
fi

#====================================================
#     INSTALLING PREREQUISITES
#====================================================

# Installing prerequisite packages
echo "Updating and upgrading the system..."
if [[ "$UNAME" == Darwin* ]] ; then
    brew install wget unzip gcc make
elif [[ "$UNAME" == Linux* ]] ; then
    sudo apt install build-essential g++ wget unzip
else
    read -p "Which package-manager do you want to use? (pacman/chocolately) " word_pkg
    if [ "$word_pkg" == "pacman" ] || [ "$word_pkg" == "Pacman" ] ; then
        pacman -S wget unzip make
    elif [ "$word_pkg" == "chocolately" ] || [ "$word_pkg" == "Chocolately" ] || [ "$word_pkg" == "choco" ] ; then
        choco install wget unzip make
    else
        echo "Inserted package-manager $word_pkg is not supported!"
        exit
    fi
fi

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
        mkdir -p "${INCL}/doctest"
        cp "doctest-master/doctest/doctest.h" "${INCL}/doctest"
        rm -rf doctest-master
    fi
    if ! pip install hurry.filesize termcolor ; then
        echo "\"pip\" is not installed. Not a problem, it is used for very optional libraries."
    fi
fi
echo ""

#====================================================
#     COMPILATION OF THE SOURCE CODE
#     (check if doctest is installed)
#====================================================
echo "Compiling only the main code of arsenalgear (this is not a problem for the installation)..."
if ! make $main ; then
    echo "Compilation failed!"
    exit
fi

#====================================================
#     SAVING FILES INTO THE SYSTEM
#====================================================
if ! ./scripts/size_of_dir.py --paths="include lib" --message="on" ; then
    echo "\"pip\" is not installed. Not a problem, it is used for very optional libraries."
fi
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
        echo "Installing arsenalgear header files into ${INCL}..."
        mkdir -p "${INCL}/arsenalgear"
        if ! ( cp -r include/* ${INCL}/arsenalgear ) ; then
            echo "Cannot install the header file into ${INCL} position of the system!"
        fi
        echo "Installing arsenalgear lib into ${LIB} folder..."
        mkdir -p "${LIB}"
        if ! ( cp -r lib/* ${LIB} ) ; then
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