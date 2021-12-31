
#include <iostream>
#include <thread>
#include <chrono>
#include "IpcController.h"

using namespace std;

int main() {

    cout<<"Client!!"<<endl;
    char buffer[MEM_SIZE] = {0,};
    int key = 0;

    cout<< "Please input key value of Server> ";
    cin >> key;

    cout<< endl;

    if (key == 0) {
        cout << "Please input integer";
        return 0;
    }
    
    IpcController ipc(key);
    if (ipc.create() == false) {
        cout << "ipc creation failed"<<endl;
        return 0;
    }

    while(1) {
        ipc.write(buffer, MEM_SIZE);
        this_thread::sleep_for(chrono::milliseconds(2000));

    }
    return 0;
}