set(PROJECT_NAME serverRunner)
set(ROOT_PROJECT_NAME SecurityCamera10)
################################################################################
# Source groups
################################################################################
add_executable(${PROJECT_NAME} "main.cpp")

################################################################################
# Target
################################################################################
target_link_libraries(${PROJECT_NAME} PRIVATE ${ROOT_PROJECT_NAME} ProtoLib)