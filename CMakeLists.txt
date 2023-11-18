cmake_minimum_required(VERSION 3.0.0)
project(CrossyRoad VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SFML_LIB_DIR "C:/SFML-2.5.1/lib")
set(SFML_INCLUDE_DIR "C:/SFML-2.5.1/include")

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

include_directories(include ${CMAKE_SOURCE_DIR}/header)

file(GLOB MAIN_SOURCES "source/*.cpp")
file(GLOB GUI "source/GUIComponent/*.cpp")
file(GLOB SCENEGRAPH "source/SceneGraph/*.cpp")
file (GLOB ROAD "source/SceneGraph/Road/*.cpp")
file (GLOB STATE "source/State/*.cpp")
file (GLOB GAMESTATE "source/State/GameState/*.cpp") 
file (GLOB RESOURCES "source/Resources/*.cpp") 
file (GLOB GAMESTATE "source/State/GameState/*.cpp") 
file (GLOB RESOURCES "source/Resources/*.cpp") 

set(SOURCES ${MAIN_SOURCES})

add_executable(CrossyRoad ${SOURCES} ${GUI} ${SCENEGRAPH} ${ROAD} ${STATE} ${GAMESTATE} ${RESOURCES})
target_link_libraries(CrossyRoad PRIVATE sfml-system sfml-window sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_custom_command(TARGET CrossyRoad POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${PROJECT_SOURCE_DIR}/media"
        $<TARGET_FILE_DIR:CrossyRoad>/media)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)