
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
There are 2 build approaches for __Linux X11__ and __Microsoft Windows__ has been covered in 2 parallel documentations in details.  

the main build documentation will guide you through those two instructions on how to build Qt statically and how to link our widget application itself statically against Qt libraries and as well as C++ runtime Libraries (so eventually there will be no dependency on Microsoft Visual C++ Redistributable on Windows).
and As it meant to, by static build there will be no more requirment for Qt and it's shared libraries being redistrebuted yet on Loinux there might be third party dependencies neeed despite those depndencies might not be pre-installed on major Linux distributions, however are addressed by Qt officiall 
documentaion which you will find refrences to them here, accordingly I expect anyone who follow these instruction will find a way to a successfull build! :)  


__Main build documentation available__ [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/BUILd_DOC.md)
Linux X11 build documentation [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/LINUX_DOC.md)  
Microsoft Windows documentation [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/WIN_DOC.md) 
Cmake documentation here [here](https://github.com/babakhajizadeh/todoList/blob/documentation/docs/CMAKE_DOC.md)  

#### Disclaimer
latest succesfull build tested on commit [9039ca5](https://github.com/qt/qt5/commit/9039ca53a3dac14415cea435083bb96f0acdb3d8) of Qt version 5.15 
```sh
git checkout 9039ca53a3dac14415cea435083bb96f0acdb3d8
```

## Acknowledgement
This project has been developed under Mentorship of __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ whom my special thanks goes with.


