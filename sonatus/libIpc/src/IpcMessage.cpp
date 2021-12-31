
#include <iostream>
#include <sstream>
#include <regex>

#include "IpcMessage.h"

bool IpcMessage::serializeIpcRequest(string str, char* output, int size) {

    regex reg("([0-9]+)[ \t]*([+-/*])[ \t]*([0-9]+)");
    if (regex_match(str, reg) == false) {
        return false;
    }

    smatch match;
    if (regex_match(str, match, reg)) {
      for (size_t i = 0; i < match.size(); i++) {
        std::cout << "Match : " << match[i].str() << " " <<match.size()<< std::endl;
      }
    }

    if (match.size() != 4) {
        return false;
    }

    IpcRequest request = {requestId(), match[2].str()[0], stoi(match[1].str()),stoi(match[3].str())};

    memcpy(output, &request, size);

    return true;
}

bool IpcMessage::deSerializeIpcRequest(char* input, int size, IpcRequest* request) {
    memcpy(request, &input, size);
    return true;
}

int IpcMessage::requestId() {
    srand((unsigned int)time(NULL));
    return rand();
}