cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)



project(ImageUtility)

find_package(OpenCV REQUIRED)
add_subdirectory(UtilityFunctions)


add_executable(ImageUtility ImageUtility.cpp)


target_link_libraries(ImageUtility PUBLIC UtilityFunctions
                      "${OpenCV_LIBS}")

target_include_directories(ImageUtility PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/UtilityFunctions"
                           "${OpenCV_INCLUDE_DIRS}")


                      