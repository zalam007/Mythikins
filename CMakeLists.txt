CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

#Add tests here as needed
ADD_EXECUTABLE(ItemTests
    testing/ItemTester.cpp
)


TARGET_LINK_LIBRARIES(ItemTests gtest)
TARGET_COMPILE_DEFINITIONS(ItemTests PRIVATE gtest_disable_pthreads=ON)