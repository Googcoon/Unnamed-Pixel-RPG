cmake_minimum_required(VERSION 3.23)
project(Unnamed-RPG-Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Unnamed-RPG-Game
        source/main.cpp include/core/Game.hpp source/core/Game.cpp include/math/Vector2.hpp source/core/TextureManager.cpp include/core/TextureManager.hpp include/core/Input.hpp source/core/Input.cpp)

include_directories(
"include"
"C:\\VulkanSDK\\1.3.224.1\\Include"
)


target_link_libraries(
${CMAKE_PROJECT_NAME}
"C:\\VulkanSDK\\1.3.224.1\\Lib\\SDL2.lib"
"C:\\VulkanSDK\\1.3.224.1\\Lib\\SDL2_image.lib"
)



