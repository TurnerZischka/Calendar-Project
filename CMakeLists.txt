CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(finalProject)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(calendar src/main.cpp src/main.cpp src/Task.cpp src/WeekSpatial.cpp)
ADD_EXECUTABLE(test test/tests.cpp )





TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
