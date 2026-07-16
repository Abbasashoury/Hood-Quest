# cmake settings
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# build type for debug or release
set(CMAKE_BUILD_TYPE Debug)

# compiler flags for debugging
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# initialize the directories for source and header files 
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# initialize the source files
set(SOURCES
${SOURCE_DIR}/main.cpp
${SOURCE_DIR}/src/Controller/InputHandler.cpp
${SOURCE_DIR}/src/Controller/SaveLoadManager.cpp
${SOURCE_DIR}/src/Model/Algorithms/PathFinders/AStar.cpp
${SOURCE_DIR}/src/Model/Algorithms/PathFinders/Dijkstra.cpp
${SOURCE_DIR}/src/Model/Algorithms/BFS.cpp
${SOURCE_DIR}/src/Model/Core/Characters/Player.cpp
${SOURCE_DIR}/src/Model/Core/Characters/Wolf.cpp
${SOURCE_DIR}/src/Model/Core/Game/GameEngine.cpp
${SOURCE_DIR}/src/Model/Core/Game/GameState.cpp
${SOURCE_DIR}/src/Model/Core/Game/Move.cpp
${SOURCE_DIR}/src/Model/DataStructure/BST.cpp
${SOURCE_DIR}/src/Model/DataStructure/Graph.cpp
${SOURCE_DIR}/src/Model/DataStructure/Maxheap.cpp
${SOURCE_DIR}/src/Model/DataStructure/Stack.cpp
${SOURCE_DIR}/src/Model/Users/Hash.cpp
${SOURCE_DIR}/src/Model/Users/User.cpp
${SOURCE_DIR}/src/Model/Users/UserManager.cpp
${SOURCE_DIR}/src/view/CLIView.cpp
)

# initialize the header files
set(HEADERS
${INCLUDE_DIR}/Controller/InputHandler.h
${INCLUDE_DIR}/Controller/SaveLoadManager.h
${INCLUDE_DIR}/Model/Algorithms/PathFinders/AStar.h
${INCLUDE_DIR}/Model/Algorithms/PathFinders/Dijkstra.h
${INCLUDE_DIR}/Model/Algorithms/BFS.h
${INCLUDE_DIR}/Model/Core/Characters/Player.h
${INCLUDE_DIR}/Model/Core/Characters/Wolf.h
${INCLUDE_DIR}/Model/Core/Game/GameEngine.h
${INCLUDE_DIR}/Model/Core/Game/GameState.h
${INCLUDE_DIR}/Model/Core/Game/Move.h
${INCLUDE_DIR}/Model/DataStructure/BST.h
${INCLUDE_DIR}/Model/DataStructure/Graph.h
${INCLUDE_DIR}/Model/DataStructure/Maxheap.h
${INCLUDE_DIR}/Model/DataStructure/Stack.h
${INCLUDE_DIR}/Model/Users/Hash.h
${INCLUDE_DIR}/Model/Users/User.h
${INCLUDE_DIR}/Model/Users/UserManager.h
${INCLUDE_DIR}/view/CLIView.h
)

# create the executable file
add_executable(Hood_Quest ${SOURCES} ${HEADERS})

# add header paths for the compiler
target_include_directories(Hood_Quest
    PRIVATE 
    ${INCLUDE_DIR}
    ${INCLUDE_DIR}/Controller
    ${INCLUDE_DIR}/Model
    ${INCLUDE_DIR}/Model/Algorithms
    ${INCLUDE_DIR}/Model/Algorithms/PathFinders
    ${INCLUDE_DIR}/Model/Core
    ${INCLUDE_DIR}/Model/Core/Characters
    ${INCLUDE_DIR}/Model/Core/Game
    ${INCLUDE_DIR}/Model/DataStructure
    ${INCLUDE_DIR}/Model/Users
    ${INCLUDE_DIR}/view
)