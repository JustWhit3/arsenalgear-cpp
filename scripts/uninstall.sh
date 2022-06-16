#!/bin/bash

#====================================================
#     GLOBAL VARIABLES
#====================================================
declare -a headers=("arsenalgear" )
declare -a libraries=("arsenalgear.a")
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
        rm -rf "${INCL}\$header"
    fi
done

#Deleting libraries:
echo "Removing libraries into /usr/local/lib folder... "
for library in "${libraries[@]}"
do
    if [[ "$UNAME" == Darwin* || "$UNAME" == Linux* ]] ; then
        sudo rm "${LIB}/$library"
    else
        sudo rm "${INCL}\$library"
    fi
done

#Final messages:
echo ""
echo "The software has been succesfully uninstalled!"