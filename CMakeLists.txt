# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(Pico-Timer C CXX ASM)

pico_sdk_init()


################## Link to libraries ##################

# Read environment variable into a normal CMake variable
set(PICO_CONNECT $ENV{PICO_CONNECT})

if(NOT PICO_CONNECT)
    message(FATAL_ERROR "PICO_CONNECT environment variable is not set")
endif()

set(PICO_LOGGING_DIR "${PICO_CONNECT}/Pico-Logging")

if(NOT EXISTS "${PICO_LOGGING_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "Expected PicoLogging CMakeLists.txt at ${PICO_LOGGING_DIR}/CMakeLists.txt")
endif()

add_subdirectory("${PICO_LOGGING_DIR}" "${CMAKE_BINARY_DIR}/Pico-Logging")

######################################################

file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)


add_library(Pico-Timer STATIC ${SOURCES})

pico_set_program_name(Pico-Timer "Pico-Timer")
pico_set_program_version(Pico-Timer "0.1")

pico_enable_stdio_uart(Pico-Timer 0)
pico_enable_stdio_usb(Pico-Timer 0)

target_include_directories(Pico-Timer PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/include"
)

target_link_libraries(Pico-Timer 
    PRIVATE
    PicoLogging      # from installed package
    pico_stdlib
)
