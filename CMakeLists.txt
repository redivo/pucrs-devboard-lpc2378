cmake_minimum_required(VERSION 2.6)
project (pucrs-devboard-lpc2378)

####################################################################################################
# Configuration
####################################################################################################
set(SOURCE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(BINARY_SRC_DIR ${CMAKE_CURRENT_BINARY_DIR}/src)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles --specs=nosys.specs")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${SOURCE_SRC_DIR}/lpc2378_flash.ld")
set(COMPILE_C TRUE)
set(COMPILE_ASSEMBLY TRUE)
set(COMPILE_HEX TRUE)

# Avoid known bug in linux giving:
#    arm-none-eabi-gcc: error: unrecognized command line option '-rdynamic'
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

# Build src diretory
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
