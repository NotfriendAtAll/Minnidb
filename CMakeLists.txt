cmake_minimum_required(VERSION 3.20)
project(db)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HEAD_FILE 
 Include/global.h 
 Include/InputBuffer.h
 Include/Btree.h
 

)


set(SOURCE_FILE 
src/global.cpp 
src/InputBuffer.cpp
src/Btree.cpp
DB.cpp
)


set(ALL_FILE ${HEAD_FILE} ${SOURCE_FILE})
add_executable(db  ${ALL_FILE})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Include)