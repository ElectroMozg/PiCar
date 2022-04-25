cmake_minimum_required(VERSION 3.16)
project(main)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
add_executable(main main.cpp bcm2835.h bcm2835.c Dualshock4.h Dualshock4.cpp CarDriver.cpp CarDriver.h)
target_link_libraries(${PROJECT_NAME} -lncurses)
