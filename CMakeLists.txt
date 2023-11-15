cmake_minimum_required(VERSION 3.0.0)
project(CrossyRoad VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(include ${CMAKE_SOURCE_DIR}/header)
file(GLOB MAIN_SOURCES "source/*.cpp")
file(GLOB GUI "source/GUIComponent/*.cpp")
file(GLOB SCENEGRAPH "source/SceneGraph/*.cpp")
file (GLOB ROAD "source/SceneGraph/Road/*.cpp")
file (GLOB STATE "source/State/*.cpp")
file (GLOB GAMESTATE "source/State/GameState/*.cpp") 
file (GLOB RESOURCES "source/Resources/*.cpp") 

set(SOURCES ${MAIN_SOURCES})

add_executable(CrossyRoad ${SOURCES} ${GUI} ${SCENEGRAPH} ${ROAD} ${STATE} ${GAMESTATE} ${RESOURCES})
target_link_libraries(CrossyRoad sfml-system sfml-window sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
