
#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>

#include "IpcController.h"
#include "IpcMessage.h"

using namespace std;

int main() {

    cout<<"Client!!"<<endl;
    string key;
    int nKey = -1;

    cout<< "Please enter key value of Server> ";
    getline(cin, key);

    try{
        nKey = stoi(key);
    }
    catch (int expn) {
        cout << "input value is invalid";
        return 0;
    }
    
    IpcController ipc(nKey);
    if (ipc.create() == false) {
        cout << "ipc creation failed"<<endl;
        return 0;
    }

    while(1) {
        cout<< "Please enter command(ex: 1+2 )> ";
        string command;
        char buff [MEM_SIZE];

        getline(cin, command);
        IpcMessage message;
        if (message.serializeIpcRequest(command, buff) == false) {
            cout<<"commnad is invalid"<<endl;
        }
        else {
            ipc.write(buff, sizeof(IpcRequest));
	    ipc.signal();
            this_thread::sleep_for(chrono::milliseconds(1000));

            ipc.wait();

            memset(buff, 0, MEM_SIZE);
            ipc.read(buff, sizeof(IpcResponse));

            if (buff[0] != 0) {
                IpcResponse response;
                if (message.deSerializeIpcResponse(buff, &response) == true) {
                    cout << "Receive response :" << buff << " " << response.status << " " << response.requestId<< " " << response.result <<endl;
                   // break;
                }
            }

        }
    }
    ipc.free(); 
    return 0;
}
