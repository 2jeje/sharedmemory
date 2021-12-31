
#include <iostream>
#include <thread>
#include <chrono>
#include "IpcController.h"
#include "IpcMessage.h"

using namespace std;

int main() {

    cout<<"Client!!"<<endl;
  //  char buffer[MEM_SIZE] = {0,};
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
        char buff [BUFFER_SIZE];

        getline(cin, command);
        IpcMessage message;
        if (message.serializeIpcRequest(command, buff) == false) {
            cout<<"commnad is invalid"<<endl;
        }

        ipc.write(buff, MEM_SIZE);
       // this_thread::sleep_for(chrono::milliseconds(2000));

    }
    return 0;
}