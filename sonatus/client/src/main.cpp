
#include <iostream>
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

    ipc.write(buffer, MEM_SIZE);
    // while(1) {
    //     ipc.read(buffer);
        
    //     if(buffer[0] == 1) {
    //         cout << "Receive data from shared memory!" << endl;
    //         break;
    //     }
    // }
    ipc.free();
    return 0;
}
