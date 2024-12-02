cmake_minimum_required(VERSION 3.5)
project(ascii-image)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16)
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0)
find_package(ImageMagick COMPONENTS Magick++)


set(CMAKE_CXX_FLAGS "-g")

file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${ImageMagick_Magick++_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${ImageMagick_Magick++_LIBRARY})



