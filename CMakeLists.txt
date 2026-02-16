cmake_minimum_required(VERSION 3.16)

project(SVGEditor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Qt's automatic tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt (Widgets module)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

set(PROJECT_SOURCES
    ./source/Qt_Part/qt_main.cpp
    ./source/Qt_Part/qt_call.cpp
    ./source/Qt_Part/qt_canvas.cpp
    ./source/Qt_Part/qt_canvas_preview.cpp
    ./source/Qt_Part/qt_canvas_objCreate.cpp
    ./source/Qt_Part/qt_dialog.cpp
    ./source/graphic_class.cpp
    ./source/Shapes/circle.cpp
    ./source/Qt_Part/qt_canvas_objModify.cpp
    ./source/DocManager/doc_manager.cpp
    ./source/DocManager/vec_manager.cpp
    ./source/DocManager/action_manager.cpp
)

set(PROJECT_HEADERS
    ./include/Qt_Part/qt_call.hpp
    ./include/Qt_Part/qt_canvas.hpp
    ./include/Qt_Part/qt_canvas_preview.hpp
    ./include/Qt_Part/qt_canvas_objCreate.hpp
    ./include/graphic_class.hpp
    ./include/Shapes/circle.hpp
    ./include/point.hpp
    ./include/Qt_Part/qt_canvas_objModify.hpp
    ./include/DocManager/doc_manager.hpp
    ./include/DocManager/vec_manager.hpp
    ./include/DocManager/action_manager.hpp)

add_executable(SVGEditor
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_include_directories(SVGEditor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(SVGEditor
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)
