set(PROJECT_NAME SecurityCamera10)

################################################################################
# Source groups
################################################################################
set(Headers
    "SafeQueue.h"
    "Backend.h"
	"Camera.h"
    "CalcAvarage.h"
    "config.h"
    "Detection.h"
    "framework.h"
    "pch.h"
    "YOLOdetection.h"
    "Logger.h"
    "sqlite3.h"
    "Sqlite.h"
    "Configuration.h"
    "CameraClient.h"
    "BackendService.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "SafeQueue.cpp"
    "Backend.cpp"
    "Camera.cpp"
    "CalcAvarage.cpp"
    "pch.cpp"
    "YOLOdetection.cpp"
    "Logger.cpp"
    "sqlite3.c"
    "Sqlite.cpp"
    "Configuration.cpp"
    "CameraClient.cpp"
    "BackendService.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})
################################################################################
# find packages
################################################################################
if(WIN32)
    set(OpenCV_DIR "C:\\opencv\\build")
endif()

find_package(OpenCV REQUIRED)

if(WIN32)
    set(spdlog_DIR "C:\\spdlog\\build")
endif()

find_package(spdlog REQUIRED CONFIG)

if(WIN32)
    set(nlohmann_json_DIR "C:\\nlohmann_json\\build")
endif()

find_package(nlohmann_json 3.2.0 REQUIRED)

################################################################################
# Target
################################################################################
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS} ProtoLib spdlog::spdlog nlohmann_json::nlohmann_json)

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS} ${spdlog_INCLUDE_DIRS})