# Cmake Instruction 

## Standard setup
Cmake is a required tool that controles and manage C++ compiler and instruct it how to find and build sources and provides ability of cross compilation which makes cmake platform independent 

here we have pretty standard cmake configuration for Qt widget except two control condition  yhat detects whether it is Windows platfrom running the Cmake or it is a Linux machine

the _if_ on line 17 and _if_ on line 40 take cares about platform specific commands.

### Disclaimer
on Microsoft Windows 10 compiling with MSVC 2022 and as well as MSVC 2019 you may notice there are Linker errors where I guess the option -static-runtime malfunctions nad MSVC may still try to link dynamic rutime libraries flaged with /MD to static ones flagged as /MT. the Workaround I realized was those two _if_ conditions which manage to take care about proper flag being addressed to the linker. yet comment them out if you encounterd 
unexpected errors.  

Latest succesfull build tested on commit [9039ca5](https://github.com/qt/qt5/commit/9039ca53a3dac14415cea435083bb96f0acdb3d8) of Qt version 5.

### Index
__Main build documentation available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/BUILd_DOC.md)__  
__Build for Linux X11 detailed documentation is available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/LINUX_DOC.md)__  
__Build for Microsoft Windows detailed documentation is available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/WIN_DOC.md)__

### Acknowledgement
Handling of this documentation is supervised by Mentor __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ 
