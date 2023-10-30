cmake_minimum_required(VERSION 3.0.0)
project(CS202_CrossyRoad)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

include(CTest)
enable_testing()

include_directories(
    ${CMAKE_SOURCE_DIR}/header
    ${CMAKE_SOURCE_DIR}/header/GUI
    ${CMAKE_SOURCE_DIR}/header/Resources
    ${CMAKE_SOURCE_DIR}/header/SceneGraph
    ${CMAKE_SOURCE_DIR}/header/SceneGraph/Road
    ${CMAKE_SOURCE_DIR}/header/State
    ${CMAKE_SOURCE_DIR}/header/State/GameState
)

file(GLOB SOURCES
    "source/*.cpp"
    "source/GUIComponent/*.cpp"
    "source/SceneGraph/*.cpp"
    "source/SceneGraph/Road/*.cpp"
    "source/State/*.cpp"
    "source/State/GameState/*.cpp"
)

add_executable(CS202_CrossyRoad ${SOURCES})
target_link_libraries(CS202_CrossyRoad sfml-system sfml-window sfml-graphics)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
