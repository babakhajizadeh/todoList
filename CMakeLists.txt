cmake_minimum_required(VERSION 3.5)

project(todoList VERSION 0.1 LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

# change directory to Qt's build directory after make and make install
set(CMAKE_PREFIX_PATH "~/qt_5.15.2_static")


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

#find_package(Wayland)
#find_package(EGL)
#find_package(XCB)
#find_package(GLIB2)
#find_package(WaylandScanner)



add_executable(todoList
    main.cpp
    chatbox.h
    chatbox.cpp
    addbutton.h
    addbutton.cpp
    mainwidget.cpp
    mainwidget.h
    serialize.cpp
    serialize.h
    chatlabel.h
    chatlabel.cpp
                  )


target_link_libraries(todoList PRIVATE Qt5::Core Qt5::Widgets)



