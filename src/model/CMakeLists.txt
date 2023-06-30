cmake_minimum_required(VERSION 3.22.1)
project(Model VERSION 1.0 LANGUAGES CXX)

set(SOURCE_LIB ModelEngineForward.cc)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})

add_subdirectory(Test)
add_subdirectory(Config)
list(APPEND EXTRA_LIBS Config Test)


target_include_directories(${PROJECT_NAME}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )

target_link_libraries(${PROJECT_NAME} PUBLIC tutorial_compiler_flags ${EXTRA_LIBS})