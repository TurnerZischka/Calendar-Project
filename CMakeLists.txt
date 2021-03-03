CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(finalProject)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(calendar src/main.cpp  src/Task.cpp src/WeekSpatial.cpp src/control.cpp)





