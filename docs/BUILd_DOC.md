## Build of Qt from source code   
Before we start please note that this is not an official documentation and my aim is only to provide a fast hand-on guide 
to help you with building Qt from Source and link against it statically.  
on these build approaches i will use __GCC verioon 11__ for linux and __MSVC 2022 v143__ available via Build tools for visual Studio 2022. And it is also tested on build tools for __MSVC 2019__.
latest LTS version for Qt5 is 5.15 i have tested on on commit [9039ca5](https://github.com/qt/qt5/commit/9039ca53a3dac14415cea435083bb96f0acdb3d8) and I expect it continue to work on Qt's update on this branch as well. Qt has backward compatablity so you could even clone and build this with Qt6 source code you may not experience major issues.  

## Downloading Qt's ource code:
Thre are several way to get your Qt's source code oficial documentation used all them concurrently yet its is recommended to get your source via git repositories and or via Qt's archive Tarball on linux and or Zip on Windows;
on either platform we will get our source codes via Git.

## Qt's build prerequisties  
on both Windows and Linux there will be need some tools and compilers to have our source get built.  
i will provide detailed descriptions on those tools and how to get them on your system in each platform's specific build documentations.  

## Linux X11 build instruction
Follow our detailed instruction on how to build Qt source and our program statically
on __Microsoft Windows__ machines specificly specifically tested on latest Uuntu LTS 22.04 [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/LINUX_DOC.md)

## Microsoft Windows build instruction
we will use __Microsoft windows 10__ for our build and __Native VS2022 BuildTools. 
Follow our detailed instruction on how to build Qt source and our program statically
on Linux X11 machines [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/WIN_DOC.md)

## Cmake
__Also Cross platform Cmake setting instruction is available__ [here] [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/CMAKE_DOC.md)  

### Acknowledgement
Handling of this documentation is supervised by Mentor __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ 