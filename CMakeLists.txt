cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19...3.22)

set(MBED_APP_JSON_PATH mbed_app.json5)
set(CUSTOM_TARGETS_JSON_PATH custom_targets/custom_targets.json5)

include(mbed-os/tools/cmake/mbed_toolchain_setup.cmake)

project(MyMbedApp LANGUAGES C CXX ASM) 

include(mbed_project_setup)

add_subdirectory(custom_targets)
add_subdirectory(mbed-os)

add_executable(${PROJECT_NAME} main.cpp)

# NUCLEO_F446RE
if(MBED_TARGET STREQUAL "NUCLEO_F446RE")
   target_sources(mbed-os INTERFACE
      ${CMAKE_CURRENT_LIST_DIR}/mbed-os/targets/TARGET_STM/TARGET_STM32F4/clock_cfg/TARGET_STM32F4_180MHZ/system_clock.c
   )
endif()

target_link_libraries(${PROJECT_NAME} mbed-os)
mbed_set_post_build(${PROJECT_NAME})
