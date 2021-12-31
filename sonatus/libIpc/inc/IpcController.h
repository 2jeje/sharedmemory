#ifndef IPC_CONTROLLER_H
#define IPC_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

#define  MEM_SIZE  4096
using namespace std;

struct IpcLock
{
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexAttr;
    char buffer[MEM_SIZE];
};

class IpcController {

public:
    IpcController(int key = -1) {
        if (key == -1) {
            srand((unsigned int)time(NULL));
            key = rand();
        }

        this->key = key;
        this->shmid = 0;
        this->lockptr = NULL;
        cout<<"key : " << this->key <<endl;
    }

    bool create();
    bool write(char* data, int size);
    bool read(char* data, int size);
    bool free();
private:
    int key;
    int shmid;
    //void* shmAddr;
    IpcLock* lockptr;
};

#endif