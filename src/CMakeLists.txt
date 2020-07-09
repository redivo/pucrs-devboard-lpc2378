include_directories (${SOURCE_INCLUDE_DIR})

# Build assembly files
set(EXTRA_FILES_TO_COMPILE "${BINARY_SRC_DIR}/crt.o")
add_custom_command(
    OUTPUT ${BINARY_SRC_DIR}/crt.o
    COMMAND arm-none-eabi-as -mapcs-32 -mcpu=arm7tdmi -o ${BINARY_SRC_DIR}/crt.o ${SOURCE_SRC_DIR}/crt.S
    DEPENDS ${SOURCE_SRC_DIR}/crt.S
)
add_custom_target(crt ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/crt.o)

############
# Base Lib #
############
add_library(base STATIC
    base.c
)

############
# Time Lib #
############
add_library(time STATIC
    time.c
)

################
# LCD 16x2 Lib #
################
add_library(lcd16x2 STATIC
    lcd_16x2.c
)

############
# GPIO Lib #
############
add_library(gpio STATIC
    gpio.c
)

###########
# LED Lib #
###########
add_library(led STATIC
    led.c
)

# Installation
install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/crt.o
    DESTINATION ${CMAKE_BINARY_DIR}/install/src
)
install(
    TARGETS time lcd16x2 base gpio led
    DESTINATION ${CMAKE_BINARY_DIR}/install/lib/
)
install(
    DIRECTORY ${SOURCE_INCLUDE_DIR}
    DESTINATION ${CMAKE_BINARY_DIR}/install/
    FILES_MATCHING PATTERN "*.h*"
)
