# CMakeList.txt : CMake project for lp little ai c++, include source and define
# project specific logic here.
#
link_directories("glut")
add_executable (CMakeTarget "lp little ai c++.cpp" "lp little ai c++.h")

# Add source to this project's executable.

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

add_custom_command(TARGET CMakeTarget POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${CMAKE_CURRENT_SOURCE_DIR}/glut/glut32.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:CMakeTarget>)    