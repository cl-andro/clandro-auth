cmake_minimum_required(VERSION 3.5)
project(clandro-auth VERSION 1.5.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
include_directories(${PROJECT_SOURCE_DIR})

find_library(LIB_CRYPTO crypto)

add_library(clandro-auth SHARED clandro-auth.c)
target_link_libraries(clandro-auth ${LIB_CRYPTO})
install(TARGETS clandro-auth DESTINATION lib)
install(FILES ${PROJECT_SOURCE_DIR}/clandro-auth.h DESTINATION include)

add_executable(passwd passwd.c)
target_link_libraries(passwd clandro-auth)
install(TARGETS passwd DESTINATION bin)

add_executable(pwlogin pwlogin.c)
target_link_libraries(pwlogin clandro-auth)
install(TARGETS pwlogin DESTINATION bin)

add_executable(testauth testauth.c)
target_link_libraries(testauth clandro-auth)
