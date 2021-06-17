if(NOT BUILD_MULTICOPTER_PLUGIN)
  return()
endif()

#if(BUILD_SIMPLE_CONTROLLER_SAMPLES)
  choreonoid_add_simple_controller(QuadcopterControllerROS QuadcopterControllerROS.cpp)
  target_link_libraries(QuadcopterControllerROS ${roscpp_LIBRARIES} CnoidMulticopterPlugin)

  #install(FILES QuadcopterTwist.cnoid DESTINATION ${CNOID_SHARE_SUBDIR}/project)
#endif()
