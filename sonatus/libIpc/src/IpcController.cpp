#include <sys/types.h>
#include <sys/shm.h>

#include "IpcController.h"

bool IpcController::create() {
    cout<<"IpcController::create()"<<endl;
    if((shmid = shmget((key_t)key, MEM_SIZE, IPC_CREAT| IPC_EXCL | 0666)) == -1) {
       cout<<"create() shmget failed"<<endl;
       return false;
        // shmid = shmget((key_t)key, MEM_SIZE, IPC_CREAT| 0666);
        
        // if(shmid == -1)
        // {
        //     cout<<"create() shmget failed"<<endl;
        //     return false;
        // }
        // else
        // {
        //     free();
        //     shmid = shmget((key_t)key, MEM_SIZE, IPC_CREAT| 0666);
            
        //     if(shmid == -1) {
        //         cout<<"create() shmget failed"<<endl;
        //         return false;
        //     }
        // }
   }

   cout<<"create() shmget success"<<endl;
   return true;
}

// bool IpcController::createProxy() {

//     if((shmid = shmget((key_t)key, 0, 0)) == -1) {
//         cout<<"createProxy() shmget success"<<endl;
//         return false;
//     }
    
//     return true;
// }

bool IpcController::write(char* data, int size) {
    cout<<"IpcController::write()"<<endl;
    void *shmaddr;
    if(size > MEM_SIZE) {
        cout<<"Shared memory size over"<<endl;
        return false;
    }
    
    if((shmaddr = shmat(shmid, (void *)0, 0)) == (void *)-1)  {
        cout<<"Shmat1 failed"<<endl;
        return false;
    }
    
    memcpy((char *)shmaddr, data, size);
    
    if(shmdt(shmaddr) == -1) {
        cout<<"Shmat2 failed"<<endl; 
        return false;
    }
    return true;
}

bool IpcController::read(char* data) {
   // cout<<"IpcController::read()"<<endl;
    void *shmaddr;
    char mess[MEM_SIZE] = {0};
    
    if((shmaddr = shmat(shmid, (void *)0, 0)) == (void *)-1) {
       // cout<<"Shmat1 failed"<<endl;
        return false;
    }
    
    memcpy(data, (char *)shmaddr, sizeof(mess));
    
    if(shmdt(shmaddr) == -1) {
       // cout<<"Shmdt2 failed"<<endl;
        return false;
    }
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