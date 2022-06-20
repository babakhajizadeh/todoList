# Build on Linux  

## Qt for Linux build  
In order to ensure a succesfull build on Linux machines we need some Prerequisites & Dependencies,  
First make sure you have available __GGC compiler__ buy installing _build essential_.  
```sh
$ sudo apt install build-essential
```
Then you have to make sure installed Qt's official build requirments [here](https://doc.qt.io/qt-6/linux-requirements.html)
### All desktop build tools  
It is neccesary to ensure you have these tools below already installed on your machine.  
Most of Linux systems provide them implicitly installed.  

* Git
* Perl
* Python

for a build we need first get our source code.  
## Cloning Qt source  
In this demonstration app I will sue only _qtbase_ sumbodule in case you need you can compile whole Qt source or whatever you need to.
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
Once you done initializaton of submodule(s) you need, you are ready for configuration:

```sh
$./configure -static -prefix ~/desired/path/to/static/build
```
And then build and install by running:

```sh
$ make && make install
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

### Acknowledgement
Handling of this documentation is supervised by Mentor __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ 
