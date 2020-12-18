cmake_minimum_required(VERSION 3.10)

project(threadsqt)

find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
)

set(CMAKE_AUTOMOC ON)


add_executable(example1
    example1/main.cpp
    example1/LoopWorker.cpp
)
target_link_libraries(example1
    Qt5::Core
    Qt5::Widgets
)

add_executable(example2
    example2/main.cpp
    example2/LoopWorker.cpp
    example2/LoopManager.cpp
)
target_link_libraries(example2
    Qt5::Core
    Qt5::Widgets
)

