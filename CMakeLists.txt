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
target_link_libraries(${PROJECT_NAME} mbed-os)
mbed_set_post_build(${PROJECT_NAME})
