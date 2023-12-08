cmake_minimum_required(VERSION 3.0.0)
project(CrossyRoad VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

<<<<<<< Updated upstream
# Set the path to the SFML directory
set(SFML_DIR "D:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/cmake/SFML")
=======
set(SFML_LIB_DIR "D:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib")
set(SFML_INCLUDE_DIR "D:/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/include")
>>>>>>> Stashed changes

# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(include ${CMAKE_SOURCE_DIR}/header)
file(GLOB MAIN_SOURCES "source/*.cpp")
file(GLOB GUI "source/GUIComponent/*.cpp")
file(GLOB MENU "source/Menu/*.cpp")
file(GLOB SCENEGRAPH "source/SceneGraph/*.cpp")
file (GLOB ROAD "source/SceneGraph/Road/*.cpp")
file (GLOB STATE "source/State/*.cpp")
file (GLOB GAMESTATE "source/State/GameState/*.cpp")  

set(SOURCES ${MAIN_SOURCES})

<<<<<<< Updated upstream
add_executable(CrossyRoad ${SOURCES} ${GUI} ${MENU} ${SCENEGRAPH} ${ROAD} ${STATE} ${GAMESTATE})
target_link_libraries(CrossyRoad sfml-system sfml-window sfml-graphics)
=======
add_executable(CrossyRoad ${SOURCES} ${GUI} ${SCENEGRAPH} ${ROAD} ${STATE} ${GAMESTATE} ${RESOURCES} ${MENU})
target_link_libraries(CrossyRoad PRIVATE sfml-system sfml-window sfml-graphics)
>>>>>>> Stashed changes

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
