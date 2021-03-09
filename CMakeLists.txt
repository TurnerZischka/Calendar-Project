CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(finalProject)


SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(calendar src/main.cpp  src/Task.cpp src/WeekSpatial.cpp src/control.cpp)

ADD_EXECUTABLE(tests src/Task.cpp src/WeekSpatial.cpp src/control.cpp src/tests.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)





