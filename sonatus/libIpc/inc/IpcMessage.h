#ifndef IPC_MESSAGE_H
#define IPC_MESSAGE_H

#include <string>
#include "model/IpcRequest.h"
#include "model/IpcResponse.h"

using namespace std;

class IpcMessage {

public:
    bool serializeIpcRequest(string str, char* output);
    bool deSerializeIpcRequest(char* input, IpcRequest* request);

    bool serializeIpcResponse(IpcResponse* response, char* output);
    bool deSerializeIpcResponse(char* input, IpcResponse* response);

private:
    int requestId();

};

#endif
