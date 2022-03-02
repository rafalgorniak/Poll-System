cmake_minimum_required(VERSION 3.4)



project(project)

#Store in a local variable SOURCE_FILES set of project's source files
set(SOURCE_FILES
        src/main.cpp
        ../library/src/Vote.cpp ../library/include/Vote.h ../library/src/SingleVote.cpp ../library/include/SingleVote.h ../library/src/MultiVote.cpp ../library/include/MultiVote.h)
#Use above set of files to build executable file Program
add_executable(project ${SOURCE_FILES})

find_package(SFML 2.4 COMPONENTS graphics window system REQUIRED)

#Specify include directory of Program subproject to global list.
#Thanks to this all other subprojects will be able to "see" this directory.
target_include_directories(project PUBLIC include)



#Specify dependency between projects Program and Library
target_link_libraries(project LIBRARY sfml-graphics sfml-window sfml-system)
