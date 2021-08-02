# Main cmake file 


cmake_minimum_required(VERSION 2.6)

cmake_policy(SET CMP0015 NEW)
cmake_policy(SET CMP0074 NEW)

set( OutputDir ${CMAKE_SOURCE_DIR}/lib)




# Find packages
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(glew REQUIRED)
FIND_PACKAGE(glm REQUIRED)
FIND_PACKAGE(GLFW3 REQUIRED)


file(GLOB GLUtils_SRC
    "*.cpp"
)

file(GLOB GLUtils_INC
    "../include/*.h"
    "*.h"
)


source_group(src FILES ${GLUtils_SRC} )
source_group(include FILES ${GLUtils_INC} )


add_compile_definitions(_WITH_CAMERA)
add_compile_definitions(GLM_ENABLE_EXPERIMENTAL)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_definitions(-DWITH_EXPORT)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OutputDir})
set(CMAKE_DEBUG_POSTFIX d)


# Create an executable
add_library(${PROJECT_NAME} STATIC ${GLUtils_SRC} ${GLUtils_INC} )



# Add libraries
target_link_libraries(${PROJECT_NAME}   ${GLEW_LIBS} ${GLEW_LIBS} ${GLFW3_LIBS} ${OPENGL_LIBRARIES}   )


set_target_properties( ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OutputDir} )
set_target_properties( ${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OutputDir} )

