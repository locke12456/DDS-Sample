cmake_minimum_required(VERSION 2.6)
project(SEMACloudDDSClient)

message("empty")
set(CURRENT_DIR ${CMAKE_SOURCE_DIR}/dds_client/client)
set(TYPES_DIR ${CMAKE_SOURCE_DIR}/dds_client/types)

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

	add_definitions("-DlibSemaDDS_EXPORTS")
    add_definitions("-D_SCL_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_WIN32_WINNT=0x0501")
    if (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
        #set this flag, otherwise the boost uintXX define will conflicate with VC stdint.h
    endif (${CMAKE_C_COMPILER_VERSION} VERSION_LESS 16.0)
endif(WIN32)

file(GLOB_RECURSE SEMACloudDDSClient
	${CURRENT_DIR}/src/CheckStatus.cpp
	#${CURRENT_DIR}/src/DDSEntityManager.cpp
)

file(GLOB_RECURSE DDS_MANAGER_FILES
	${CURRENT_DIR}/src/DDSManager.cpp
	${CURRENT_DIR}/src/DDSMessageReader.cpp
	${CURRENT_DIR}/src/DDSMessageWriter.cpp
	${CURRENT_DIR}/src/DDSParticipant.cpp
	${CURRENT_DIR}/src/DDSPublisher.cpp
	${CURRENT_DIR}/src/DDSRegister.cpp
	${CURRENT_DIR}/src/DDSSubscriber.cpp
	${CURRENT_DIR}/src/DDSTopicCreator.cpp
	${CURRENT_DIR}/inc/DDSManager.h
	${CURRENT_DIR}/inc/DDSMessageReader.h
	${CURRENT_DIR}/inc/DDSMessageWriter.h
	${CURRENT_DIR}/inc/DDSParticipant.h
	${CURRENT_DIR}/inc/DDSPublisher.h
	${CURRENT_DIR}/inc/DDSRegister.h
	${CURRENT_DIR}/inc/DDSSubscriber.h
	${CURRENT_DIR}/inc/DDSTopicCreator.h
	${CURRENT_DIR}/inc/IDDSObject.h
)
FILE(GLOB_RECURSE SEMADDS_FILES
	${CURRENT_DIR}/src/SEMADDSClient.cpp
	${CURRENT_DIR}/inc/SEMADDSClient.h
)
MakeGroup( "DDS_MANAGER_FILES" "DDSManager" "CURRENT_DIR")
MakeGroup( "SEMADDS_FILES" "DDSClient" "CURRENT_DIR")
file(GLOB_RECURSE SEMACloudDDSClientDll
)

INCLUDE_DIRECTORIES(${CURRENT_DIR}/inc)
INCLUDE_DIRECTORIES(${TYPES_DIR}/inc)

ADD_LIBRARY( SEMACloudDDSClient SHARED
	${SEMACloudDDSClient}
	${DDS_MANAGER_FILES}
	${SEMADDS_FILES}
	${SEMACloudDDSClientDll}
)
ADD_EXECUTABLE( MessageSubscriber
	#${SEMACloudDDSClient}
	${CURRENT_DIR}/test/SEMADataSubscriber.cpp
) 
ADD_EXECUTABLE( MessagePublisher
	#${SEMACloudDDSClient}
	${CURRENT_DIR}/test/SEMADataPublisher.cpp
) 

target_link_libraries( SEMACloudDDSClient ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES( SEMACloudDDSClient SEMACloudDDSTypes )
TARGET_LINK_LIBRARIES( SEMACloudDDSClient ddskernel )
TARGET_LINK_LIBRARIES( SEMACloudDDSClient dcpssacpp )
if(UNIX)
TARGET_LINK_LIBRARIES( SEMACloudDDSClient pthread )
TARGET_LINK_LIBRARIES( MessagePublisher pthread )
TARGET_LINK_LIBRARIES( MessageSubscriber pthread )
ENDIF()

TARGET_LINK_LIBRARIES( MessagePublisher SEMACloudDDSTypes )
TARGET_LINK_LIBRARIES( MessagePublisher ddskernel )
TARGET_LINK_LIBRARIES( MessagePublisher dcpssacpp )

TARGET_LINK_LIBRARIES( MessagePublisher jsoncpp)
TARGET_LINK_LIBRARIES( MessageSubscriber SEMACloudDDSTypes )
TARGET_LINK_LIBRARIES( MessageSubscriber ddskernel )
TARGET_LINK_LIBRARIES( MessageSubscriber dcpssacpp )

TARGET_LINK_LIBRARIES( MessagePublisher SEMACloudDDSClient )
TARGET_LINK_LIBRARIES( MessageSubscriber SEMACloudDDSClient )
