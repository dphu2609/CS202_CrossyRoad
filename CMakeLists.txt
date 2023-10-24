cmake_minimum_required(VERSION 3.0.0)
project(CrossyRoad VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# Locate SFML
set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

include(CTest)
enable_testing()

# Collect source files from multiple directories
file(GLOB MAIN_SOURCES "source/*.cpp")
file(GLOB GUI "source/GUIComponent/*.cpp")
file(GLOB SCENEGRAPH "source/SceneGraph/*.cpp")
file (GLOB ROAD "source/SceneGraph/Road/*.cpp")
file (GLOB STATE "source/State/*.cpp")
file (GLOB GAMESTATE "source/State/GameState/*.cpp")    

# Create a single list of all source files
set(SOURCES ${MAIN_SOURCES})

add_executable(CrossyRoad WIN32 ${SOURCES} ${GUI} ${SCENEGRAPH} ${ROAD} ${STATE} ${GAMESTATE})

# Add include directories
target_include_directories(CrossyRoad PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header" "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/include")

target_compile_definitions(CrossyRoad PRIVATE
    SFML_STATIC
)

# Link SFML libraries to the executable (static versions)
target_link_libraries(CrossyRoad PRIVATE
    -static-libgcc
    -static-libstdc++
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    opengl32
    freetype
    winmm
    gdi32
)

# Enable specific flags
target_compile_options(CrossyRoad PUBLIC -fdiagnostics-color=always -g -mwindows)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



# --------------------------------------------------------- NON STATIC VERSION ---------------------------------------------------------

# cmake_minimum_required(VERSION 3.0)
# project(CrossyRoad VERSION 0.1.0 LANGUAGES C CXX)

# # Set the C++ standard to use
# set(CMAKE_CXX_STANDARD 14)

# # Find the SFML package
# set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
# find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# include(CTest)
# enable_testing()

# # Collect source files from multiple directories
# file(GLOB MAIN_SOURCES "source/*.cpp")

# # Create a single list of all source files
# set(SOURCES ${MAIN_SOURCES})

# # Create the executable
# add_executable(CrossyRoad ${SOURCES})

# target_include_directories(CrossyRoad PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header" "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/include")

# # Link the SFML libraries to your project
# target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

