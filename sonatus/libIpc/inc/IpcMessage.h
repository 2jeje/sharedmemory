#ifndef IPC_MESSAGE_H
#define IPC_MESSAGE_H

#include <string>
#include "model/IpcRequest.h"
#include "model/IpcResponse.h"

using namespace std;
#define BUFFER_SIZE 100

class IpcMessage {

public:
    bool serializeIpcRequest(string str, char* output, int size);
    bool deSerializeIpcRequest(char* input, int size, IpcRequest* request);

private:
    int requestId();

};

#endif
