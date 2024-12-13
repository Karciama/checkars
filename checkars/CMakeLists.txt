cmake_minimum_required(VERSION 3.29)
project(checkars)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "C:/Users/User/Documents/SFML/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(checkars main.cpp
        Lenta.cpp
        Lenta.h
        Rules.cpp
        Rules.h
        Visual.cpp
        Visual.h
        Visual.cpp
        Visual.h)

target_include_directories(checkars PRIVATE C:/Users/User/Documents/SFML/SFML-2.6.2/include)
target_link_libraries(checkars sfml-graphics sfml-window sfml-system)