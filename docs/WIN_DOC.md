# Build Qt on Microsoft Windows

## Setting up Prerequisites:
For a succesfull static build of Qt on Microsoft Windows on MSVC (Microsoft Visual C++) compiler a safe approach is having 
_Build Tools for Visual Studio 2022_ Installed, where available at [here](https://visualstudio.microsoft.com/downloads/?q=build+tools) and It automatically setup tools needed for C++ Desktop Development. however standard Visual Studio setip will also cover what is needed.  
You need to verify you have alread have installed tools below:

#### Prerequisites:
* __Perl__ from https://strawberryperl.com/
* __Python__ (>v.3)http://www.python.org/download/
* __Cmake__ (>v3.2) (available within MSVC BuildTools)

## Cloning Qt Source  
In this demonstration app I will only get _qtbase_ submodule in case you need you can compile whole Qt source or include whatever you need to.
And I download it from official Qt repository on Github
__Start by cloning into Qt's supermodule_
```sh
$ git clone https://github.com/qt/qt5
```
 Now check out latest Qt5 branch 5.15  
 ```sh
$ git checkout 5.15
```
 Then use __perl__ to initialize _qtbase_ submodule
 ```sh
$ perl init-repository --module-subset=qtbase
```
## Configuring and Building Qt source
Once you done initializaton of submodule(s) you need, you are ready "for" configuration:  
Now run (on 64bit Windows)  
```sh X64 Native Tools Command Prompt for VS 2022 ```  
and on X86 Windows
```sh X86 Native Tools Command Prompt for VS 2022 ``` 
To have Visual Studio build environment initialized.    
then you need to set up requaired environment variables;  

```sh
set QTDIR=C:\qt5\qtbase 
set PATH=%QTDIR%\bin;%PATH%
set INSTALL_PATH=%QTDIR%\static-build"
```
QTDIR refers to where you have cloned Qt's source and it is recommended to setup on root folder of drive C:    
Remember all _bin_ directories of every Qt submodule needs be added to PATH and as well as well as all Prerequisites mentioned above otherwise you might encounter build errors. check their setup by running:
```sh
where perl.exe
where python.exe
where cmake.exe
where ninja.exe
```
Once you ensured everything is ready run Configure command to set up your build:

```sh
configure.bat -release -prefix "C:\prefred\instaled\path" -opensource -platform win32-msvc -no-opengl -static -nomake examples -
```
I have used _-no-opengl_ option as it is not needed for widget apps however if your testing your build on QML QtQuick application you will need to include _-opengl desktop_ or other options 

## Installing Qt
Finally you can install Qt: 
```sh
nmake && nmake install
```
## Program's static build
First you need to provide address of your own Qt's static build directory in __CMakeLists.txt__ at __CMAKE_PREFIX_PATH__ variable.  
So by now I Assume you have already finished tasks above, And you have swiched to our programs root directory;
 
```sh  
$ mkdir build
cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make
```
### Cleaning
To get your Qt directory clean and back to to first stage after a try,
```sh
$ git submodule foreach --recursive "git clean -dfx" && git clean -dfx
```

### Disclaimer
Latest succesfull build tested on commit [9039ca5](https://github.com/qt/qt5/commit/9039ca53a3dac14415cea435083bb96f0acdb3d8) of Qt version 5.

### Index
__Main build documentation available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/BUILd_DOC.md)__  
__Build for Linux X11 detailed documentation is available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/LINUX_DOC.md)__  
__Build for Microsoft Windows detailed documentation is available [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/WIN_DOC.md)__
__Cmake documentation here__ [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/CMAKE_DOC.md)  

### Acknowledgement
Handling of this documentation is supervised by Mentor __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ 
