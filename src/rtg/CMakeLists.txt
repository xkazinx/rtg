# rtg for a web browser (WebAssembly, Emscripten). Windows builds it from rtg.vcxproj
# (build.ps1); this file is the web one, run by build_web.ps1 against kazilib's SFML
# web build (kazilib web/build_deps.ps1):
#   emcmake cmake -S src/rtg -B <build> -G Ninja -DSFML_DIR=...
# Output: index.html / .js / .wasm - the folder kazin.dev/projects/rtg serves.
cmake_minimum_required(VERSION 3.21)
project(rtg_web CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RTG_SRC ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 3 REQUIRED COMPONENTS Graphics)
include(${RTG_SRC}/dep/kazilib/web/kazilib_web.cmake)

file(GLOB RTG_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(rtg ${RTG_SOURCES})
kazilib_web_target(rtg)
target_include_directories(rtg PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rtg PRIVATE SFML::Graphics)
