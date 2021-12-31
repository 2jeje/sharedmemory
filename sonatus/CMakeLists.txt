project(SONATUS)

#
# libIPC
#

set(LIBIPC_SOURCES
    "./libIpc/src/IpcController.cpp"
)

add_library(Ipc SHARED ${LIBIPC_SOURCES})

target_include_directories(Ipc PRIVATE "./libIpc/inc")




#
# Server
#

# set(SERVER_HEADERS
#     "./include/"
# )

set(SERVER_SOURCES
    "./server/src/main.cpp"
)

# add_executable(Server ${MAIN_HEADERS} ${MAIN_SOURCES})
add_executable(Server ${SERVER_SOURCES})

target_include_directories(Server PRIVATE "./libIpc/inc")

target_link_libraries(Server Ipc)