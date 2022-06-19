cmake_minimum_required(VERSION 3.2)

project(todoList VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# change directory to Qt's build directory after on tour platform 
# windows contain double \\ in adress e.g. C:\\Qt5\\static
set(CMAKE_PREFIX_PATH "~/qt_5.15.2_static")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)

#uncoment if condition only in case of mismach rutime value error 
if(WIN32)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif(WIN32)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

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

if(WIN32)
set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()
endif(WIN32)

target_link_libraries(todoList PRIVATE Qt5::Widgets)

