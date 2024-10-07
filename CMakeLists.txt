set(CMAKE_MINIMUM_REQUIRED_VERSION 3.10.0)

project(qt_valid)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenSSL REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)


add_executable(${PROJECT_NAME} main.cpp mainwindow.cpp)

add_executable(ssl ssl.cpp)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

target_link_libraries(ssl OpenSSL::Crypto)

