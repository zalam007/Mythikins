CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(PlayerTester
    testing/PlayerTester.cpp
    src/
)

TARGET_LINK_LIBRARIES(PlayerTester gtest)
TARGET_COMPILE_DEFINITIONS(PlayerTester PRIVATE gtest_disable_pthreads=ON)