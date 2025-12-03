cmake_minimum_required(VERSION 3.25)


project(http_server)

include_directories(include)

add_library(server src/server.cpp src/request.cpp src/response.cpp)

add_executable(main main.cpp)

add_executable(client client.cpp)

target_link_libraries(main server)