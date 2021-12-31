#ifndef IPC_REQUEST_H
#define IPC_REQUEST_H

struct IpcRequest {
    int requestId;
    char op;
    int lparam;
    int rparam;
};

#endif