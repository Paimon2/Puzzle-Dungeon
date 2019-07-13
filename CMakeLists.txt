cmake_minimum_required(VERSION 3.0)


project(Puzzle-Dungeon)
add_compile_options(-m64 -std=c++11)

set(EXECUTABLE_OUTPUT_PATH
    ${Puzzle-Dungeon_SOURCE_DIR}/Binaries)

file(GLOB SRCS
    Puzzle\ Dungeon/Main.cpp
    Puzzle\ Dungeon/lever.hpp
    Puzzle\ Dungeon/GameInstance.hpp
    Puzzle\ Dungeon/GUIToolkit.hpp
    Puzzle\ Dungeon/Helpers.hpp
    Puzzle\ Dungeon/Level.hpp
    Puzzle\ Dungeon/PauseMenu.hpp
    Puzzle\ Dungeon/EventHandler.hpp
    Puzzle\ Dungeon/Tile.hpp
    Puzzle\ Dungeon/Character.hpp
    Puzzle\ Dungeon/GameData.hpp
    Puzzle\ Dungeon/MainMenu.hpp
    Puzzle\ Dungeon/Question.hpp
    Puzzle\ Dungeon/Utilities.hpp

)




set(SFML_DIR "SFML (Linux)/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
add_executable(${PROJECT_NAME} ${SRCS})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system sfml-audio)
endif()

 
