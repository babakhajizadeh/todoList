
![License](https://img.shields.io/badge/license-GPL-green)
![Technology](https://img.shields.io/badge/-Qt%20C%2B%2B%20GUI-bright)

# TodoList

__TodoList, A simple Qt 6 GUI application (Linux,X11 build).__  
I hardly could imagine this tool might have any real life end user usage beside the
the fact that it is developed to be served as a Hello-world program with some humble
functionalities which is an instance demonstration of some Qt technologies and as well
as an additional instruction how to build solid application.It run independently from Qt
framework itself to acquire cross-platform portability which is a root value in Qt world.
## Under the hood
Simple but variant,as said this is only for demonstration purpose so what it
actually demonstrates?  
TodoList application with it’s simple GUI has written solely written manually, without use of Qt
Designer.I tried to focus and Object Orientally implement Qt Signal and Slot approach
which is in it’s soul a solution for implementing Observer Design pattern and also it covers
various concepts and technologies e.g. Data Serialization, Data Encoding and use of
QIODevice technology, Data structure like QVarient class and QjsonDocument are also invloved.  
At end user,it writes edit and saves tasks into a visual Todo list.  
## Build  
__X11 / Debian based distributions (Debian/Ubuntu/Mint)__  
First it is recommended officially by Qt to install dependencies mentioned 
in [here](https://doc.qt.io/qt-5/linux-requirements.html). Via standard package manager
or Snap.   
## Qt static build
for static build it is required to have static build of qt from source. it's source package latest version available via Qt
official repository [here](https://github.com/qt) 
so I assume you have already download the source and are ready to build your Qt static version.  
Navigate into source directory and start with configuring your build settings:  

```sh
$./configure -static -prefix ~/desired/path/to/static/build
```
once configuration succeed then run:  

```sh
$ make && make install
```
## Program static build  

Once you had your Qt build finished switch back to to cloned code directory make a build folder navigate to and run:
```sh
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make
```

### Acknowledgement
This project has been developed under Mentorship of __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ whom my special thanks goes to.


