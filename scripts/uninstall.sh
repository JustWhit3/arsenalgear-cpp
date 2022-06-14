#!/bin/bash

#====================================================
#     GLOBAL VARIABLES
#====================================================
declare -a headers=("arsenalgear" )
declare -a libraries=("arsenalgear.a")
if [[ "$UNAME" == Darwin* ]] ; then
    INCLUDE=$(pcre-config --cflags)
    LIB=$(pcre-config --libs)
fi

#====================================================
#     UNINSTALL THE REPOSITORY
#====================================================
echo ""
echo "Uninstalling the repository..."

#Deleting header files:
echo "Removing headers into /usr/local/include folder..."
for header in "${headers[@]}"
do
    if [[ "$UNAME" == Darwin* ]] ; then
        sudo rm -rf "${INCLUDE:2}/$header"
    else
        sudo rm -rf /usr/local/include/"$header"
    fi
done

#Deleting libraries:
echo "Removing libraries into /usr/local/lib folder... "
for library in "${libraries[@]}"
do
    if [[ "$UNAME" == Darwin* ]] ; then
        sudo rm -rf "${LIB:2}/$header"
    else
        sudo rm /usr/local/lib/"$library"
    fi
done

#Final messages:
echo ""
echo "The software has been succesfully uninstalled!"