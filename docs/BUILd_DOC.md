# Build of Qt from source code  

Before we start please note that this is not an official documentation and my aim is only to provide a fast hand-on guide 
to help you with building Qt from Source and link against it statically.  
on these build approaches I will use __GCC verioon 11__ for linux and __MSVC 2022 v143__ available via Build tools for visual Studio 2022. And it is also tested on Build Tools for __MSVC 2019__.
latest LTS version for Qt5 is 5.15 I have tested on on commit [9039ca5](https://github.com/qt/qt5/commit/9039ca53a3dac14415cea435083bb96f0acdb3d8) and I expect it continue to work on Qt's update on this branch as well. Qt has backward compatablity so you could even clone and build this with Qt6 source code you may not experience major issues.  

## Downloading Qt's ource code:
Thre are several way to get your Qt's source code.Oficial documentation used all them concurrently however its is recommended to get your source via git repositories and or via Qt's archive Tarball on linux and or Zip on Windows;  
On either platform I will get my source codes via Git.

## Qt's build prerequisties  
on both Windows and Linux there will be need for some tools and compilers to have our source get compiled.  
I will provide a detailed descriptions on those tools and how to get them on your system in each platform's specific build documentations.  

## Linux X11 build instruction
Follow my detailed instruction on how to build Qt source and the program statically
on linux machines specifically tested on latest __Ubuntu LTS 22.04__ [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/LINUX_DOC.md)

## Microsoft Windows build instruction
we will use __Microsoft windows 10__ for our build and __Native VS 2022 BuildTools. 
Follow our detailed instruction on how to build Qt source and our program statically
on Linux X11 machines [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/WIN_DOC.md)

## Cmake
__Also Cross platform Cmake setting instruction is available__ [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/CMAKE_DOC.md)  

### Acknowledgement
Handling of this documentation is supervised by Mentor __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ 