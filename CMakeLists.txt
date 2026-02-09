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
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(SVGEditor
    main.cpp
    qt_call.cpp
    canvas.cpp
)

target_include_directories(SVGEditor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(SVGEditor
    Qt6::Widgets
)
