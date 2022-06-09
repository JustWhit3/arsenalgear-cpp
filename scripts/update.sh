#!/bin/bash

#====================================================
#     UPDATING THE REPOSITORY
#====================================================
echo ""
echo "Updating the repository..."
echo ""

#Deleting old files and downloading the new repo:
cd ..
rm -rf arsenalgear*

#Downloading new ones:
wget https://github.com/JustWhit3/arsenalgear-cpp/archive/main.zip
mv main.zip arsenalgear-cpp-main.zip
unzip arsenalgear-cpp-main.zip
rm arsenalgear-cpp-main.zip
mv arsenalgear-cpp-main arsenalgear
echo ""
echo "Repository is up-to-date!"
echo ""
echo "Enter the following commands:"
echo "1. cd .."
echo "2. cd arsenalgear-cpp"
echo ""