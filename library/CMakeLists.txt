cmake_minimum_required(VERSION 3.4)
project(LIBRARY)

set(SOURCE_FILES

        include/Voter.h
        include/Vote.h
        include/SingleVote.h
        include/MultiVote.h
        include/Poll.h
        include/Option.h
        include/SingleChoicePoll.h
        include/MultiChoicePoll.h
        include/DataStorage.h
        include/Display.h
        include/PollSystem.h

        src/Voter.cpp
        src/Vote.cpp
        src/SingleVote.cpp
        src/MultiVote.cpp
        src/Poll.cpp
        src/Option.cpp
        src/SingleChoicePoll.cpp
        src/MultiChoicePoll.cpp
        src/Display.cpp
        src/DataStorage.cpp
        src/PollSystem.cpp

        src/PercentageStrategy.cpp include/PercentageStrategy.h src/AbsolutePercentage.cpp include/AbsolutePercentage.h src/RelativePercentage.cpp include/RelativePercentage.h)

#create shared library of type STATIC, SHARED or MODULE using following source files
add_library(LIBRARY ${SOURCE_FILES})

target_include_directories(LIBRARY PUBLIC include)

if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


set(SOURCE_TEST_UNIT_FILES
        tests/master.cpp
        tests/VotingTest.cpp
        tests/PollTest.cpp
        src/Vote.cpp include/Vote.h src/SingleVote.cpp include/SingleVote.h src/MultiVote.cpp include/MultiVote.h)
add_executable (votingTest ${SOURCE_TEST_UNIT_FILES})

target_include_directories(votingTest PUBLIC include)

target_link_libraries (votingTest
        LIBRARY
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_executable (pollTest
        tests/master.cpp
        tests/PollTest.cpp)

target_include_directories(pollTest PUBLIC include)

target_link_libraries (pollTest
        LIBRARY
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_executable (dataTest
        tests/master.cpp
        tests/DataStorageTest.cpp)

target_include_directories(dataTest PUBLIC include)

target_link_libraries (dataTest
        LIBRARY
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_executable (systemTest
        tests/master.cpp
        tests/PollSystemTest.cpp)

target_include_directories(systemTest PUBLIC include)

target_link_libraries (systemTest
        LIBRARY
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

enable_testing()

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
