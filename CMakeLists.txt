project(Project_3D_Printer CXX)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/crypto_cmake")
find_package( CryptoPP REQUIRED )
target_link_libraries(${PROJECT_NAME} cryptopp)
