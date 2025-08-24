cmake_minimum_required(VERSION 3.16)
project(Gr2D_DX8to9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Configure WzLib
add_subdirectory(WzLib EXCLUDE_FROM_ALL)

# Create library
add_library(${PROJECT_NAME} SHARED
    DllMain.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "Gr2D_DX8"
    LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/Gr2D.def"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE
    WzLib
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/Gr2D_DX9.dll"
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
)