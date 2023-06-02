cmake_minimum_required(VERSION 3.26)
project(CPPTextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(handlerlib)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Alpha_Editor main.cpp MainWindow.cpp EditorWidget.cpp
        LineNumberArea.cpp PopUpWindow.cpp FileDocker.cpp)

include_directories(handlerlib)

target_link_libraries(Alpha_Editor
        Qt::Core
        Qt::Gui
        Qt::Widgets
        handlerlib
        )
