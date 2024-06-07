CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

#Add tests here as needed
ADD_EXECUTABLE(MythikinTester
    testing/MythikinTester.cpp
)

ADD_EXECUTABLE(AttackTester
    testing/AttackTester.cpp
)

TARGET_LINK_LIBRARIES(MythikinTester gtest)
TARGET_COMPILE_DEFINITIONS(MythikinTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(AttackTester gtest)
TARGET_COMPILE_DEFINITIONS(AttackTester PRIVATE gtest_disable_pthreads=ON)