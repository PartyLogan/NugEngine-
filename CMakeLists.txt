cmake_minimum_required(VERSION 3.22)

project(
  NugEngine
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME})

add_subdirectory(libs/sdl)
add_subdirectory(libs/sdl-image)
add_subdirectory(libs/sdl-mixer)
add_subdirectory(libs/sdl-ttf)
add_subdirectory(libs/glm)
add_subdirectory(src)

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  include
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
  SDL3::SDL3 
  SDL3_image::SDL3_image
)

add_custom_target(
  copy-compile-commands ALL
  ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_BINARY_DIR}/compile_commands.json
  ${CMAKE_CURRENT_LIST_DIR}
)
