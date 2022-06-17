#!/bin/bash

#====================================================
#     GLOBAL VARIABLES
#====================================================
declare -a headers=("arsenalgear" )
declare -a libraries=("arsenalgear.a")
if [[ "$UNAME" == Darwin* ]] ; then
    INCL=/usr/local/include
    LIB=/usr/local/lib
elif [[ "$UNAME" == Linux* ]] ; then
    INCL=/usr/include/
    LIB=/usr/lib/
else
    INCL="C:\include"
    LIB="C:\lib"
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
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo rm -rf "${INCL}/$header"
    else
        rm -rf "${INCL}/$header"
    fi
done

#Deleting libraries:
echo "Removing libraries into /usr/local/lib folder... "
for library in "${libraries[@]}"
do
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo rm "${LIB}/$library"
    else
        rm "${INCL}/$library"
    fi
done

#Final messages:
echo ""
echo "The software has been succesfully uninstalled!"