cmake_minimum_required(VERSION 3.5)

project(todoList VERSION 0.1 LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

# change directory to Qt's build directory after make and make install
set(CMAKE_PREFIX_PATH "~/QtStatic")


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

#find_package(Wayland)
#find_package(EGL)
#find_package(XCB)
#find_package(GLIB2)
#find_package(WaylandScanner)



add_executable(todoList
    source/main.cpp
    source/chatbox.h
    source/chatbox.cpp
    source/addbutton.h
    source/addbutton.cpp
    source/mainwidget.cpp
    source/mainwidget.h
    source/serialize.cpp
    source/serialize.h
    source/chatlabel.h
    source/chatlabel.cpp
                  )


target_link_libraries(todoList PRIVATE Qt6::Core Qt6::Widgets)



