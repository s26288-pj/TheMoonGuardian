cmake_minimum_required(VERSION 3.24)
project(Moon_Guardian_-_The_Awakening)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_INCLUDE_DIR D:/WORK/SDL2-2.30.1/include)
set(SDL2_LIB_DIR D:/WORK/SDL2-2.30.1/lib/x64)
set(SDL2_IMAGE_INCLUDE_DIR D:/WORK/SDL2_image-2.8.2/include)
set(SDL2_IMAGE_LIB_DIR D:/WORK/SDL2_image-2.8.2/lib/x64)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
add_executable(${PROJECT_NAME} "Source Files/main.cpp"
        "Header Files/Player.h"
        "Header Files/InputManager.h"
        "Source Files/InputManager.cpp"
        "Header Files/Graphics.h"
        "Source Files/Graphics.cpp"
        "Header Files/GameManager.h"
        "Source Files/GameManager.cpp"
        "Header Files/Timer.h"
        "Source Files/Timer.cpp"
        "Header Files/GameEntity.h"
        "Header Files/MathHelper.h"
        "Source Files/GameEntity.cpp"
        "Header Files/Texture.h"
        "Source Files/Texture.cpp"
        "Source Files/AssetManager.cpp"
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib ${SDL2_LIB_DIR}/SDL2main.lib)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB_DIR}/SDL2.lib
        ${SDL2_LIB_DIR}/SDL2main.lib ${SDL2_IMAGE_LIB_DIR}/SDL2_image.lib)

