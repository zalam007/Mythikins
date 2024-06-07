CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

#Add tests here as needed
ADD_EXECUTABLE(MythikinTester
    testing/MythikinTester.cpp
)

ADD_EXECUTABLE(MythidexTester
    testing/MythidexTester.cpp
    src/Mythidex.cpp
)

TARGET_LINK_LIBRARIES(MythikinTester gtest)
TARGET_COMPILE_DEFINITIONS(MythikinTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(MythidexTester gtest)
TARGET_COMPILE_DEFINITIONS(MythidexTester PRIVATE gtest_disable_pthreads=ON)