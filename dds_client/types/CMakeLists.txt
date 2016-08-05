cmake_minimum_required(VERSION 2.6)
project(SEMACloudDDSTypes)

message("empty")
set(CURRENT_DIR ${CMAKE_SOURCE_DIR}/dds_client/types)

project(SEMACloudEdgePro)
# Add OS specific build options
if(UNIX)
    add_definitions("-DLINUX -O2 -s -Wall")
	set( CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} --32" )
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )
endif(UNIX)

if(WIN32)
    if(MSVC_VERSION EQUAL 1700)
      add_definitions(-D_VARIADIC_MAX=10)
    endif()

    add_definitions("-DSEMA_BUILD_LIB")
    add_definitions("-D_SCL_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501")
    if (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
        #set this flag, otherwise the boost uintXX define will conflicate with VC stdint.h
    endif (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
endif(WIN32)

file(GLOB_RECURSE SEMACloudDDSTypes
	${CURRENT_DIR}/src/*.cpp
)
file(GLOB_RECURSE SEMACloudDDSTypesDll
	${CURRENT_DIR}/src/stdafx.cpp
	${CURRENT_DIR}/src/dllmain.cpp
)

INCLUDE_DIRECTORIES(${CURRENT_DIR}/inc)

ADD_LIBRARY( SEMACloudDDSTypes SHARED
	${SEMACloudDDSTypes}
	${SEMACloudDDSTypesDll}
)

TARGET_LINK_LIBRARIES( SEMACloudDDSTypes ddskernel )
TARGET_LINK_LIBRARIES( SEMACloudDDSTypes dcpssacpp )