#include <sys/types.h>
#include <sys/shm.h>

#include "IpcController.h"

bool IpcController::create() {
    cout<<"IpcController::create()"<<endl;
    shmid = shmget((key_t)key, MEM_SIZE, IPC_CREAT| 0666);
        
    if(shmid == -1) {
        cout<<"create() shmget failed"<<endl;
        return false;
    }

    if((shmAddr = shmat(shmid, (void *)0, 0)) == (void *) -1) {
        cout<<key<< " create()::shmat failed "<< std::strerror(errno) <<endl;
        return false;
    }

   cout<<"create() shmget success"<<endl;
   return true;
}

bool IpcController::write(char* data, int size) {
    cout<<"IpcController::write() "<< data << endl;
    if(size > MEM_SIZE) {
        cout<<"Shared memory size over"<<endl;
        return false;
    }
    
    memcpy((char *)shmAddr, data, size);
    return true;
}

bool IpcController::read(char* data, int size) {
    memcpy(data, (char *)shmAddr, size);
   // printf( "Data read from shared data :   %s\n", (char *)data);
    return true;
}

bool IpcController::free() {
    cout<<"IpcController::free()"<<endl;
    if(shmctl(shmid, IPC_RMID, 0) == -1) {
        cout<<"free() shmctl failed"<<endl;
        return false;
    }
    return true;
}