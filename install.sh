#!/bin/bash
echo "Updating apt-get"
sudo apt-get update 
echo "Installing freeGLUT for windowing API and I/O operations"
sudo apt-get -y install freeglut3 
echo "Installing header files for FreeGLUT3"
sudo apt-get -y install freeglut3-dev 
echo "Installing linker for ELF files"
sudo apt-get -y install binutils-gold 
echo "Installing G++ CMAKE"
sudo apt-get -y install g++ cmake 
echo "Installing libglew-dev "
sudo apt-get -y install libglew-dev 
echo "Installing C++ compiler"
sudo apt-get -y install g++ 
echo "Installing mesa for OpenGL compatible 3D graphics"
sudo apt-get -y install mesa-common-dev 
echo "Installing build-essentials"
sudo apt-get -y install build-essential
echo "Installing GLM"
sudo apt-get -y install libglew1.5-dev libglm-dev 
echo "Installing mesa-utils"
sudo apt-get -y install mesa-utils 
echo $(glxinfo | grep "OpenGL version")