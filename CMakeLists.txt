CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(PlayerTester
    testing/PlayerTester.cpp
    src/
)

#Add tests here as needed
ADD_EXECUTABLE(ItemTester
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


ADD_EXECUTABLE(BattleTester
    testing/BattleTester.cpp
    src/Battle.cpp
    src/Team.cpp
)

file(GLOB SOURCES "src/*.cpp")

ADD_EXECUTABLE(WildBattleTester
    testing/WildBattleTester.cpp
    ${SOURCES}
)

ADD_EXECUTABLE(PCTester
    testing/PCTester.cpp
)

ADD_EXECUTABLE(LocationTester
    testing/LocationTester.cpp
)

TARGET_LINK_LIBRARIES(ItemTester gtest)
TARGET_COMPILE_DEFINITIONS(ItemTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(MythikinTester gtest)
TARGET_COMPILE_DEFINITIONS(MythikinTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(AttackTester gtest)
TARGET_COMPILE_DEFINITIONS(AttackTester PRIVATE gtest_disable_pthreads=ON)


TARGET_LINK_LIBRARIES(BattleTester gtest)
TARGET_COMPILE_DEFINITIONS(BattleTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(WildBattleTester gtest)
TARGET_COMPILE_DEFINITIONS(WildBattleTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(PCTester gtest)
TARGET_COMPILE_DEFINITIONS(PCTester PRIVATE gtest_disable_pthreads=ON)


TARGET_LINK_LIBRARIES(LocationTester gtest)
TARGET_COMPILE_DEFINITIONS(LocationTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(MythidexTester gtest)
TARGET_COMPILE_DEFINITIONS(MythidexTester PRIVATE gtest_disable_pthreads=ON)

TARGET_LINK_LIBRARIES(PlayerTester gtest)
TARGET_COMPILE_DEFINITIONS(PlayerTester PRIVATE gtest_disable_pthreads=ON)

