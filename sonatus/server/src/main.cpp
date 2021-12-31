
#include <iostream>
#include <thread>
#include <chrono>

#include "IpcController.h"
#include "IpcMessage.h"

using namespace std;

int main() {

    cout<<"Server!!"<<endl;

    IpcController ipc;
    if (ipc.create() == false) {
        cout << "create failed!" << endl;
        return 0;
    }

    while(1) {
        char buff [BUFFER_SIZE] = {0,};
        int processingRequestId = -1;

        ipc.read(buff, sizeof(IpcRequest));
        if (buff[0] != 0) {

            IpcMessage message;
            IpcRequest request;
            if (message.deSerializeIpcRequest(buff, &request) == true) {
                cout << "Receive request :" << request.requestId << " " << request.op<< " " << request.lparam <<  " " << request.rparam<<endl;
                double result = 0;
                int status = 200;
                switch (request.op) {
                    case '+':
                        result = request.lparam + request.rparam;
                        break;
                    case '-':
                        result = request.lparam - request.rparam;
                        break;
                    case '*':
                        result = request.lparam * request.rparam;
                        break;
                    case '/':
                        result = request.lparam / request.rparam;
                        break;
                    default:
                        status = 400;
                        break;
                }

                IpcResponse response = {status, request.requestId, result};
                cout << "send response :" << response.status << " " << response.requestId<< " " << response.result <<endl;

                memset(buff, 0, BUFFER_SIZE);
                message.serializeIpcResponse(&response, buff);
                ipc.write(buff, sizeof(IpcResponse));
            }
        }

        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    ipc.free(); 
    return 0;
}