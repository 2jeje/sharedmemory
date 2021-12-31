
#include <iostream>
#include <sstream>
#include <regex>

#include "IpcMessage.h"

bool IpcMessage::serializeIpcRequest(string str, char* output) {

    regex reg("([0-9]+)[ \t]*([+-/*])[ \t]*([0-9]+)");

    smatch match;
    if (regex_match(str, match, reg) == false) {
    //   for (size_t i = 0; i < match.size(); i++) {
    //     cout << "Match : " << match[i].str() << " " <<match.size()<< endl;
    //   }
        return false;
    }

    if (match.size() != 4) {
        return false;
    }

    IpcRequest request = {requestId(), match[2].str()[0], stoi(match[1].str()), stoi(match[3].str())};
    cout << "send data " << request.requestId << " " << request.op<< " " << request.lparam <<  " " << request.rparam<<endl;
    memcpy(output, &request, sizeof(request));



    return true;
}

bool IpcMessage::deSerializeIpcRequest(char* input, IpcRequest* request) {
    IpcRequest* temp = reinterpret_cast<IpcRequest*>(input);
    memcpy(request, temp, sizeof(IpcRequest));
    return true;
}

int IpcMessage::requestId() {
    srand((unsigned int)time(NULL));
    return rand();
}