
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
There are 2 build options covered in parallel documentations  
the main build documentation will guid e you thriugh two detailed documentations on how to deploy
and statically build Qt itself and the how to go through building this demo widget application statically 
on both, __Microsoft Windows__ via microsoft MSVC compiler available at Visual Studio Build Toools 2022 and __Linux X11__ via GNU GCC compiler.  

As it meant to, by static build there will be no more requirment for Qt and it's shared libraries being on the host machine, yet there might be third party dependencies neeed it doesn't guarantee whole 3rd party dependencies are fulfilled however those dependencies are addressed by Qt officiall 
documentaion, accordingly I expect anyone who follow these instruction will find a way for a successfull build! :)  


__Main build documentation available [here]()__  
__Linux X11 build detailed documentation is available [here]()__  
__Microsoft Windows detailed documentation is available [here]()__

#### Disclaimer
latest succesfull build tested on commit c7da5c5 and Qt static version 6.3.0
```sh
git checkout c7da5c5
```

### Acknowledgement
This project has been developed under Mentorship of __Amirreza Ashouri. [AMP999](https://github.com/AMP999)__ whom my special thanks goes to.


