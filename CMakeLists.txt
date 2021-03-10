CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(finalProject)


SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(calendar src/main.cpp  src/Task.cpp src/WeekSpatial.cpp src/control.cpp)
ADD_EXECUTABLE(all_tests test/tests.cpp)

TARGET_LINK_LIBRARIES(all_tests gtest)
TARGET_COMPILE_DEFINITIONS(all_tests PRIVATE gtest_disable_pthreads=ON)

ADD_EXECUTABLE(tests src/Task.cpp src/WeekSpatial.cpp src/control.cpp test/tests.cpp)

TARGET_LINK_LIBRARIES(tests gtest)
TARGET_COMPILE_DEFINITIONS(tests PRIVATE gtest_disable_pthreads=ON)





