
#include <iostream>
#include <sstream>
#include <regex>

#include "IpcMessage.h"

bool IpcMessage::serializeIpcRequest(string str, char* output) {

    regex reg("([0-9]+)[ \t]*([+-/*])[ \t]*([0-9]+)");

    smatch match;
    if (regex_match(str, match, reg) == false) {
        return false;
    }

    if (match.size() != 4) {
        return false;
    }

    IpcRequest request = {requestId(), match[2].str()[0], stoi(match[1].str()), stoi(match[3].str())};
    memcpy(output, &request, sizeof(IpcRequest));

    return true;
}

bool IpcMessage::deSerializeIpcRequest(char* input, IpcRequest* request) {
    IpcRequest* temp = reinterpret_cast<IpcRequest*>(input);
    memcpy(request, temp, sizeof(IpcRequest));
    return true;
}


bool IpcMessage::serializeIpcResponse(IpcResponse* response, char* output) {
    memcpy(output, &response, sizeof(IpcResponse));
    return true;
}

bool IpcMessage::deSerializeIpcResponse(char* input, IpcResponse* response) {
    IpcResponse* temp = reinterpret_cast<IpcResponse*>(input);
    memcpy(response, temp, sizeof(IpcResponse));
    return true;
}


int IpcMessage::requestId() {
    srand((unsigned int)time(NULL));
    return rand();
}