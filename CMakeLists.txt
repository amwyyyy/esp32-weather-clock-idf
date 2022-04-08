cmake_minimum_required(VERSION 3.5)

if (NOT DEFINED PROJECT_NAME)
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)

    set(EXTRA_COMPONENT_DIRS "../components"
        $ENV{IDF_PATH}/examples/common_components/protocol_examples_common
    )

    project(lvgl-weather-clock)
else()
    message(FATAL_ERROR "LV PORT ESP32: This must be a project's main CMakeLists.txt.")
endif()
