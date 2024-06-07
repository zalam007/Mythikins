CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

#Add tests here as needed
ADD_EXECUTABLE(ItemTests
    testing/ItemTester.cpp
)

ADD_EXECUTABLE(MythikinTester
    testing/MythikinTester.cpp
)

ADD_EXECUTABLE(MythidexTester
    testing/MythidexTester.cpp
    src/Mythidex.cpp
)

ADD_EXECUTABLE(AttackTester
    testing/AttackTester.cpp
)

ADD_EXECUTABLE(LocationTester
    testing/LocationTester.cpp
)

TARGET_LINK_LIBRARIES(ItemTests gtest)
TARGET_COMPILE_DEFINITIONS(ItemTests PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(MythikinTester gtest)
TARGET_COMPILE_DEFINITIONS(MythikinTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(AttackTester gtest)
TARGET_COMPILE_DEFINITIONS(AttackTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(LocationTester gtest)
TARGET_COMPILE_DEFINITIONS(LocationTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(MythidexTester gtest)
TARGET_COMPILE_DEFINITIONS(MythidexTester PRIVATE gtest_disable_pthreads=ON)
