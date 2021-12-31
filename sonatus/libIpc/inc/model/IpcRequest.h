#ifndef IpcREQUEST_H
#define IpcREQUEST_H

struct IpcRequest {
    int requestId;
    char op;
    int lparam;
    int rparam;
};

#endif