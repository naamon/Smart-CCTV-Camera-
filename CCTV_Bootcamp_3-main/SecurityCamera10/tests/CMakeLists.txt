set(PROJECT_NAME tests)
set(ROOT_PROJECT_NAME SecurityCamera10)
################################################################################
# Source groups
################################################################################
set(Tests
    "test.cpp"
)

add_executable(${PROJECT_NAME} ${Tests})

################################################################################
# find packages
################################################################################
if(WIN32)
    set(OpenCV_DIR "C:\\opencv\\build")
endif()
find_package(OpenCV REQUIRED)

if(WIN32)
    set(Catch2_DIR "C:\\catch2")
endif()
find_package(Catch2 3 REQUIRED)

################################################################################
# Include directories
################################################################################
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

################################################################################
# Target
################################################################################
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})

target_link_libraries(${PROJECT_NAME} PUBLIC Catch2::Catch2WithMain)

target_link_libraries(${PROJECT_NAME} PRIVATE ${ROOT_PROJECT_NAME} Catch2::Catch2WithMain)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
