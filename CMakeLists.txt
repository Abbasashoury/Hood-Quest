# cmake settings
cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# initialize the directories for source and header files 
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# initialize the source files
set(SOURCES
${SOURCE_DIR}/main.cpp
${SOURCE_DIR}/Controller/InputHandler.cpp
${SOURCE_DIR}/Controller/SaveLoadManager.cpp
${SOURCE_DIR}/Model/Algorithm/PathFinders/AStar.cpp
${SOURCE_DIR}/Model/Algorithm/PathFinders/Dijkstra.cpp
${SOURCE_DIR}/Model/Algorithm/BFS.cpp
${SOURCE_DIR}/Model/Core/Characters/Player.cpp
${SOURCE_DIR}/Model/Core/Characters/Wolf.cpp
${SOURCE_DIR}/Model/Core/Game/GameEngine.cpp
${SOURCE_DIR}/Model/Core/Game/GameState.cpp
${SOURCE_DIR}/Model/Core/Game/Move.cpp
${SOURCE_DIR}/Model/DataStrucure/BST.cpp
${SOURCE_DIR}/Model/DataStrucure/Graph.cpp
${SOURCE_DIR}/Model/DataStrucure/Maxheap.cpp
${SOURCE_DIR}/Model/DataStrucure/Stack.cpp
${SOURCE_DIR}/Model/Users/Hash.cpp
${SOURCE_DIR}/Model/Users/User.cpp
${SOURCE_DIR}/Model/Users/UserManager.cpp
${SOURCE_DIR}/view/CLIView.cpp
)