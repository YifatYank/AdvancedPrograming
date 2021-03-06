cmake_minimum_required(VERSION 3.5)
project(unitTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES Tests/main.cpp Tests/Point.cpp Tests/Point.h Tests/Trip.cpp Tests/Trip.h Tests/Passenger.cpp Tests/Passenger.h Tests/Driver.cpp Tests/Driver.h Tests/TaxiCenter.cpp Tests/TaxiCenter.h Tests/Definitions.h Tests/Standart.cpp Tests/Standart.h Tests/Luxury.cpp Tests/Luxury.h Tests/Cab.cpp Tests/Cab.h Tests/GridNode.cpp Tests/GridNode.h Tests/Grid.cpp Tests/Grid.h Tests/PointNode.cpp Tests/PointNode.h Tests/BfsGrid.cpp Tests/BfsGrid.h Tests/Enums.h Tests/DriverTest.cpp Tests/CabTest.cpp Tests/GridTest.cpp Tests/PointNodeTest.cpp Tests/PassengerTest.cpp Tests/GridNodeTest.cpp Tests/TripTest.cpp Tests/PointTest.cpp Tests/Passenger.h Tests/oldmain.cpp Tests/mainSrialization.cpp)
add_executable(unitTest ${SOURCE_FILES} Tests/PointNodeTest.cpp Tests/PassengerTest.cpp Tests/GridNodeTest.cpp Tests/TripTest.cpp Tests/PointTest.cpp)
target_link_libraries(unitTest gtest gtest_main ${Boost_LIBRARIES})
