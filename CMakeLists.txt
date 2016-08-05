cmake_minimum_required(VERSION 2.6)

project(DDS_SAMPLE)

INCLUDE(prepare_os_env.cmake)
INCLUDE(prepare_boost.cmake)
INCLUDE(make_group.cmake)

if(${ARCH} STREQUAL "WIN32")
	set( SEMACLOUD_SDK ${CMAKE_SOURCE_DIR}/lib/win)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/win32/include)
else()
	set( SEMACLOUD_SDK ${CMAKE_SOURCE_DIR}/lib/linux)
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/posix/include)
ENDIF()
	
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/)
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/dependencies/include)
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/dwcore)
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/ilslog)
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/ilsstomp)
INCLUDE_DIRECTORIES(${SEMACLOUD_SDK}/ilsutil)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/cm)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/common)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/dcps/C++/SACPP)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/plugin)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/streams)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/sys)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/svr4)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/include/rmi)


link_directories(${SEMACLOUD_SDK}/libraries/semacloud/)
link_directories(${SEMACLOUD_SDK}/libraries/dds/)
link_directories(${LIBS_PATH}/jsoncpp/)

	
add_subdirectory(dds_client)
	
