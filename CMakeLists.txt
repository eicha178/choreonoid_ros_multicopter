cmake_minimum_required(VERSION 3.5.0)
project(choreonoid_ros_multicopter)

set(CHOREONOID_SKIP_QT_CONFIG true)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  sensor_msgs
  image_transport
  choreonoid
)

catkin_package(SKIP_CMAKE_CONFIG_GENERATION SKIP_PKG_CONFIG_GENERATION)

set(CMAKE_CXX_STANDARD ${CHOREONOID_CXX_STANDARD})
set(CMAKE_CXX_EXTENSIONS OFF)

set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS ${CHOREONOID_COMPILE_DEFINITIONS})

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${CHOREONOID_INCLUDE_DIRS}
)

link_directories(
  ${CHOREONOID_LIBRARY_DIRS}
)

add_executable(joy_to_msgs src/joy_to_msgs.cpp)
target_link_libraries(joy_to_msgs ${catkin_LIBRARIES})

add_subdirectory(src)
