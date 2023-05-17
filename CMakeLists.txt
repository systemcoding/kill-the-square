project(sdl-game)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(sdl-game
        src/Application.cpp
        src/Game.cpp
        src/World.cpp
        src/Window.cpp
        src/Character.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS})
target_link_libraries(sdl-game SDL2 SDL2_image SDL2_ttf SDL2_mixer::SDL2_mixer)

# target_link_libraries(${PROJECT_NAME} PUBLIC 
# SDL2::SDL2main
# SDL2::SDL2
# SDL2_image::SDL2_image
# SDL2_mixer::SDL2_mixer
# SDL2_ttf::SDL2_ttf
# SDL2_net::SDL2_net)
