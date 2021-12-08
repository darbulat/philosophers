cmake_minimum_required(VERSION 3.21)
project(. C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

file(GLOB philo_SRC
        "*.h"
        "*.c"
        "*/*.c"
        "*/*.h"
        )

add_executable(. ${philo_SRC})
