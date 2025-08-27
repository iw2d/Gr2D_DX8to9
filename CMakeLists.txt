cmake_minimum_required(VERSION 3.16)
project(Gr2D_DX8to9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Configure WzLib headers
set(WZLIB_INCLUDE_PATH "../include" CACHE STRING "Path to the correct WzLib include directory")

# Create library
set(LIBRARY_NAME ${PROJECT_NAME})
add_library(${LIBRARY_NAME} SHARED
    DllMain.cpp
)

set_target_properties(${LIBRARY_NAME} PROPERTIES
    OUTPUT_NAME "Gr2D_DX8"
    LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/Gr2D.def"
)

target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_17)

target_include_directories(${LIBRARY_NAME} PRIVATE
    ${WZLIB_INCLUDE_PATH}
)

add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/Gr2D_DX9.dll"
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)