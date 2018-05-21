# Timber
Replica of the Timberman Game (https://store.steampowered.com/app/398710/)

Code written for Linux OS with OpenGL 4.3 Support using SFML 2.5 Library. Adopted from the book Beginning C++ Game Programming by John horton.

The source code is released under Apache License 2.0 as specified in the LICENSE file.

Copyright (C) 2018 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

https://www.linkedin.com/in/sumandeep-banerjee-1436a17/

## Checking for Graphics Processor
The following command will tell you about the graphics processor in your system.
$ sudo lshw -C display

## Checking for OpenGL Support Version
The following command shows version information of all OpenGL components installed on your system.
$ glxinfo | grep 'OpenGL\|version'

## Installing OpenGL Development Pre-requisites
$ sudo apt-get update
$ sudo apt-get install build-essential
$ sudo apt-get install g++ cmake
$ sudo apt-get install freeglut3 freeglut3-dev binutils-gold libglew-dev mesa-common-dev libglew1.5-dev libglm-dev

## Installing SFML(Simple and Fast Multimedia Library) on Ubuntu
$ sudo apt-get install libsfml-dev

###For more information visit https://www.sfml-dev.org/tutorials/2.5/start-linux.php

Also, to link sfml library into your code use 'pkg-config --libs sfml-all' along with your g++ command