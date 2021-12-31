#ifndef IPC_RESPONSE_H
#define IPC_RESPONSE_H

struct IpcResponse {
    int status;
    int requestId;
    double result;
};

#endif
