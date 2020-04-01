cmake_minimum_required(VERSION 3.8)
project(random-3d-city)

if (WIN32)
    set(FREEGLUT_INCLUDE_DIRS "C:/Program\ Files/Common\ Files/freeglut/include")
    set(FREEGLUT_LIBRARY_DIRS "C:/Program\ Files/Common\ Files/freeglut/lib")
endif (WIN32)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14 -Wno-deprecated -Werror=return-type")

find_package (OpenGL REQUIRED)

if (APPLE)
    find_package(GLUT REQUIRED)
endif (APPLE)

if (WIN32)
    include_directories(${OPENGL_INCLUDE_DIR}  ${FREEGLUT_INCLUDE_DIRS})
    link_directories(${FREEGLUT_LIBRARY_DIRS})
elseif (APPLE)
    include_directories(${OPENGL_INCLUDE_DIR}  ${GLUT_INCLUDE_DIRS})
endif ()

file(GLOB SOURCE_FILES
        *.cpp
        *.h
        )

add_executable(graphics graphics.h graphics.cpp chunk.h chunk.cpp drawableObject.h drawableObject.cpp gameManager.h
        gameManager.cpp movableObject.h movableObject.cpp player.h player.cpp recPrism.h recPrism.cpp solid.h
        solid.cpp perlinNoiseGenerator.cpp perlinNoiseGenerator.h building.cpp building.h triPrism.cpp triPrism.h)
add_executable(testing testing.cpp chunk.h chunk.cpp perlinNoiseGenerator.cpp perlinNoiseGenerator.h)

if (WIN32)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} freeglut)
    target_link_libraries (testing ${OPENGL_LIBRARIES} freeglut)
elseif (APPLE)
    target_link_libraries (graphics ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
    target_link_libraries (testing ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif ()