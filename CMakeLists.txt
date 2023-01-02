cmake_minimum_required(VERSION 3.17)

set( CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe" )
set( CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe" )

project(projet)

set(CMAKE_CXX_STANDARD 20)

add_executable(projet src/main.cpp src/Wall.cpp headers/Wall.hpp headers/Joueur.hpp src/Joueur.cpp headers/Domino/DomTuile.hpp src/Domino/DomTuile.cpp 
headers/Domino/DomEngine.hpp src/Domino/DomEngine.cpp src/Domino/Input.cpp headers/Domino/EmplacementVide.hpp src/Domino/EmplacementVide.cpp
headers/Emplacement.hpp src/Emplacement.cpp headers/Engine.hpp src/Engine.cpp
headers/Trax/TraxEngine.hpp src/Trax/TraxEngine.cpp src/Trax/TraxInput.cpp 
headers/Tuile.hpp src/tuile.cpp headers/Trax/TraxTuile.hpp src/Trax/TraxTuile.cpp
headers/Trax/TraxTuileDroit.hpp src/Trax/TraxTuileDroit.cpp headers/Trax/TraxTuileCourbe.hpp src/Trax/TraxTuileCourbe.cpp)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(projet ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build directory
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
