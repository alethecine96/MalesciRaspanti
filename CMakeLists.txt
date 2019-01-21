cmake_minimum_required(VERSION 3.4)

# Define sources and executable

set(EXECUTABLE_NAME "menu")
add_executable(${EXECUTABLE_NAME} main.cpp menu.cpp menu.h map.h Inventory.cpp map.cpp Mappa.cpp Mappa.h Player.cpp Player.h Eyes.cpp Eyes.h MapLoader.cpp MapLoader.h Projectile.cpp Projectile.h Enemy.cpp Enemy.h Drawable.cpp Drawable.h Observer.cpp Observer.h)

# Detect and add SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()