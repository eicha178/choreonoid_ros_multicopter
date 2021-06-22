if(NOT BUILD_MULTICOPTER_PLUGIN)
  return()
endif()

#if(BUILD_SIMPLE_CONTROLLER_SAMPLES)

  choreonoid_add_simple_controller(QuadcopterControllerJoy QuadcopterControllerJoy.cpp)
  target_link_libraries(QuadcopterControllerJoy ${roscpp_LIBRARIES} CnoidMulticopterPlugin)

  choreonoid_add_simple_controller(QuadcopterControllerTwist QuadcopterControllerTwist.cpp)
  target_link_libraries(QuadcopterControllerTwist ${roscpp_LIBRARIES} CnoidMulticopterPlugin)

#endif()
