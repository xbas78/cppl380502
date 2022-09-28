cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME cppl380502)

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets
                                         WebEngineWidgets
                                         REQUIRED)

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets
                                              WebEngineWidgets
                                              REQUIRED)

#set(HEADERS)
set(SRC main.cpp)

add_executable(${PROJECT_NAME} ${SRC}
#                               ${HEADERS}
                           )

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets
                                      Qt${QT_VERSION_MAJOR}::WebEngineCore
                                      Qt${QT_VERSION_MAJOR}::WebEngineWidgets)
