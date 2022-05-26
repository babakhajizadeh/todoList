cmake_minimum_required(VERSION 3.5)

project(todoList VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.2.4/gcc_64/lib/cmake")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 find_package(Qt6 COMPONENTS REQUIRED Widgets) 
if (NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Core Widgets)
endif()



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

target_link_libraries(todoList PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)



