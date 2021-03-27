cmake_minimum_required(VERSION 3.3)

add_executable(app)

set(SOURCES
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/images/PPMImage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/Color.cpp
    )

target_sources(app PUBLIC ${SOURCES})

target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/include)
