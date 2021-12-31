#ifndef IPC_CONTROLLER_H
#define IPC_CONTROLLER_H

#include <iostream>


#define  MEM_SIZE  4096
using namespace std;

class IpcController {

public:
    IpcController(int key) {
        this->key = key;
        this->shmid = 0;
    }

    bool create();
    bool write(char* data, int size);
    bool read(char* data);
    bool free();
private:
    int key;
    int shmid;

};


#endif