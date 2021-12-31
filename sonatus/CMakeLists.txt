project(SONATUS)

#
# libIPC
#

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