FrameBook
===

Author: Ernesto Rodriguez <neto@netowork.me>

FrameBook is a Plasmoid for the KDE4 desktop environment that displays a slide show of your Facebook pictures. It includes functionality to login into Facebook and get the list of pictures.


# Requirements

You need the following software with the development packages installed to build FrameBook.

 * g++
 * QT
 * cmake
 * kdebase-plasma (KDE plasma)
 * qjson
 * ImageMagick (Magick++)

# Build

These are the typical build commands you must follow. In case you want to change the install directory, set the -DCMAKE_INSTALL_PREFIX parameter to the directory of your choice. (ie. -DCMAKE_INSTALL_PREFIX=/my/dir/) additionally make sure that directory is in your KDEDIRS environmental variable (ie. add: export KDEDIRS=/my/dir/:$KDEDIRS to your ~/.bashrc file).

Instructions:

1. cmake -DCMAKE_INSTALL_PREFIX=/usr/ .
2. make
3. sudo make install (or su -c 'make install')
