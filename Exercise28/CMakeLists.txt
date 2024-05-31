cmake_minimum_required(VERSION 3.22)

project(Exercise28 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    main.cpp
    dialog.cpp
)

set(HEADERS
    dialog.h
)

add_executable(Exercise28 ${SOURCES} ${HEADERS})
target_link_libraries(Exercise28 PUBLIC Qt6::Core Qt6::Widgets)

# Include Qt's directories
target_include_directories(Exercise28 PUBLIC ${Qt6Widgets_INCLUDE_DIRS})
target_compile_definitions(Exercise28 PUBLIC ${Qt6Widgets_DEFINITIONS})
target_compile_features(Exercise28 PUBLIC cxx_std_14)

# Enable AUTOMOC
set_target_properties(Exercise28 PROPERTIES AUTOMOC ON)
