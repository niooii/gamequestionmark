cmake_minimum_required(VERSION 3.25)
project(gamequestionmark C)
set(CMAKE_C_STANDARD 99)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#target_link_libraries(gamequestionmark -lOpenGL32 -lfreeGLUT)

add_executable(gamequestionmark main.c)

IF (WIN32)
    TARGET_LINK_LIBRARIES(server PRIVATE wsock32 ws2_32)
ENDIF ()
target_link_libraries(gamequestionmark ${OPENGL_LIBRARIES})
target_link_libraries(gamequestionmark ${GLUT_LIBRARIES})