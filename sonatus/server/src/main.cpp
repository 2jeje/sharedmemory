
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
 

        ipc.read(buff, sizeof(IpcRequest));
        if (buff[0] != 0) {
            IpcMessage message;
            IpcRequest request;
            message.deSerializeIpcRequest(buff, &request);
            cout << "Receive data " << request.requestId << " " << request.op<< " " << request.lparam <<  " " << request.rparam<<endl;
        }

        this_thread::sleep_for(chrono::milliseconds(2000));
       // if(buffer[0] == 1) {
       //     cout << "Receive data from shared memory!" << endl;
       //     break;
       // }
    }

    ipc.free(); 
    return 0;
}