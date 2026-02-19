cmake_minimum_required(VERSION 3.5)

project(Programming_Qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(COMMON_GRAPH_SOURCES
    PPP/Window.h
    PPP/Graph.h
    PPP/GUI.h
    PPP/Simple_window.h
    PPP/Point.h
    PPP/std_lib_facilities.h
    Window.cpp
    Graph.cpp
    PPP/Image_private.h
    GUI.cpp
    PPP/GUI_private.h
    Simple_window.cpp
    Colormap.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Programming_Qt
        MANUAL_FINALIZATION
        main.cpp
        ${COMMON_GRAPH_SOURCES}
    )
qt_add_executable(example01
        MANUAL_FINALIZATION
        example01.cpp
        ${COMMON_GRAPH_SOURCES}
    )
endif()

target_link_libraries(Programming_Qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(example01 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(Programming_Qt PRIVATE . ./PPP)
target_include_directories(example01 PRIVATE . ./PPP)

set_target_properties(Programming_Qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Programming_Qt)
    qt_finalize_executable(example01)
endif()
