
#include <iostream>
#include <thread>
#include <chrono>

#include "IpcController.h"

using namespace std;

int main() {

    cout<<"Server!!"<<endl;
    char buffer[MEM_SIZE] = {0,};

    IpcController ipc;
    if (ipc.create() == false) {
        cout << "create failed!" << endl;
        return 0;
    }

    while(1) {
        ipc.read(buffer);
        this_thread::sleep_for(chrono::milliseconds(2000));
        if(buffer[0] == 1) {
            cout << "Receive data from shared memory!" << endl;
            break;
        }
    }

    ipc.free(); 
    return 0;
}