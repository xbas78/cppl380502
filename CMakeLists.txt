cmake_minimum_required(VERSION 3.14)
project(CPPL380502)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64/lib/cmake")

find_package(Qt5 COMPONENTS Widgets
                            WebEngineWidgets
                            REQUIRED)

add_executable(CPPL380502 main.cpp)

target_link_libraries(CPPL380502 Qt5::Widgets
                                 Qt5::WebEngineCore
                                 Qt5::WebEngineWidgets)