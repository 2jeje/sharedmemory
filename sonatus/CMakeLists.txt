project(SONATUS)
cmake_minimum_required(VERSION 3.5)
#
# libIPC
#

set (CMAKE_CXX_FLAGS "-std=c++11 -pthread -lrt")

set(LIBIPC_SOURCES
    "./libIpc/src/IpcController.cpp"
    "./libIpc/src/IpcMessage.cpp"
)

add_library(Ipc SHARED ${LIBIPC_SOURCES})

target_include_directories(Ipc PRIVATE "./libIpc/inc")



#
# Server
#

set(SERVER_SOURCES
    "./server/src/main.cpp"
)

add_executable(Server ${SERVER_SOURCES})

target_include_directories(Server PRIVATE "./libIpc/inc")

target_link_libraries(Server Ipc)


#
# Client
#

set(CLIENT_SOURCES
    "./client/src/main.cpp"
)

add_executable(Client ${CLIENT_SOURCES})

target_include_directories(Client PRIVATE "./libIpc/inc")

target_link_libraries(Client Ipc)
