
#include <iostream>
#include "IpcController.h"

using namespace std;


int main() {

    cout<<"Server!!"<<endl;
    IpcController ipc(11);
    ipc.create();
    return 0;
}
