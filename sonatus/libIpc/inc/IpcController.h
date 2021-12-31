#ifndef IPC_CONTROLLER_H
#define IPC_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#define  MEM_SIZE  4096
using namespace std;

class IpcController {

public:
    IpcController(int key = -1) {
        if (key == -1) {
            srand((unsigned int)time(NULL));
            key = rand();
        }

        this->key = key;
        this->shmid = 0;
        cout<<"key : " << this->key <<endl;
    }

    bool create();
//    bool createProxy();
    bool write(char* data, int size);
    bool read(char* data);
    bool free();
private:
    int key;
    int shmid;
};

#endif