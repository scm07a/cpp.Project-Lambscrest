cmake_minimum_required(VERSION 3.20)

project(ProjectLambscrest LANGUAGES CXX)

# ==========================
# C++ Standard
# ==========================
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED Yes)
set(CMAKE_CXX_EXTENSIONS OFF)

# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ==========================
# Warnings
# ==========================
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# ==========================
# SDL2
# ==========================
find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_IMAGE REQUIRED SDL2_image)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
pkg_check_modules(SDL2_MIXER REQUIRED SDL2_mixer)

# ==========================
# Sources
# ==========================
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    include/*.h
)

# ==========================
# Executable
# ==========================
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    resources/icons/icon.rc
)
# ==========================
# Copy Assets
# ==========================
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)
# ==========================
# Includes
# ==========================
target_include_directories(${PROJECT_NAME}
    PRIVATE
        include
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS}
        ${SDL2_MIXER_INCLUDE_DIRS}
)

# ==========================
# Link Libraries
# ==========================
target_link_directories(${PROJECT_NAME}
    PRIVATE
        ${SDL2_LIBRARY_DIRS}
        ${SDL2_IMAGE_LIBRARY_DIRS}
        ${SDL2_TTF_LIBRARY_DIRS}
        ${SDL2_MIXER_LIBRARY_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
)