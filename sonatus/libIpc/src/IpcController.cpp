#include <sys/types.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>

#include "IpcController.h"

bool IpcController::create() {
    cout<<"IpcController::create()"<<endl;
    shmid = shmget((key_t)key, MEM_SIZE, IPC_CREAT| 0666);

    if (shmid == -1) {
        cout<<"create() shmget failed"<<endl;
        return false;
    }

    if ((lockptr = (IpcLock *)shmat(shmid, NULL, 0)) == (IpcLock *) -1) {
        cout<<key<< " create()::shmat failed "<< std::strerror(errno) <<endl;
        return false;
    }

   // memset(lockptr->buffer, 0, MEM_SIZE);

    // if (pthread_mutexattr_init( &lockptr->mutexAttr ) != 0 ) {
    //     cout<<key<< " pthread_mutexattr_initfailed "<< std::strerror(errno) <<endl;
    //     return false;
    // }

    // if (pthread_mutexattr_setpshared( &lockptr->mutexAttr,PTHREAD_PROCESS_SHARED) != 0 ) {
    //     cout<<key<< " pthread_mutexattr_setpshared "<< std::strerror(errno) <<endl;
    //     return false;
    // }

    // if (pthread_mutex_init( &lockptr->mutex, &lockptr->mutexAttr) != 0 ) {
    //     cout<<key<< " pthread_mutex_init "<< std::strerror(errno) <<endl;
    //     return false;
    // }

    if (sem_init(&sema, key, 1) < 0) {
        cout<<key<< " sem_init "<< std::strerror(errno) <<endl;
		return false;
	}

    cout<<"create() shmget success"<<endl;
    return true;
}

bool IpcController::write(char* data, int size) {
    cout<<"IpcController::write() "<< data << endl;
    if (size > MEM_SIZE) {
        cout<<"Shared memory size over"<<endl;
        return false;
    }

  //  if (pthread_mutex_lock( &lockptr->mutex ) == 0 ) {
        memcpy((char *)lockptr->buffer, data, size);
   // }

  //  pthread_mutex_unlock( &lockptr->mutex ) ;
    return true;
}

bool IpcController::read(char* data, int size) {
  //  if (pthread_mutex_lock( &lockptr->mutex ) == 0 ) {
        memcpy(data, (char *)lockptr->buffer, size);
  //  }
   // pthread_mutex_unlock( &lockptr->mutex );
   // printf( "Data read from shared data :   %s\n", (char *)data);
    return true;
}

void IpcController::lock() {
   // pthread_mutex_lock( &lockptr->mutex );
}

void IpcController::unlock() {
  //  pthread_mutex_unlock( &lockptr->mutex );
}

void IpcController::wait() {
   // pthread_cond_wait( &lockptr->cond, &lockptr->mutex);
   sem_wait(&sema);
}

void IpcController::signal() {
   // pthread_cond_signal( &lockptr->cond);
   sem_post(&sema);
}

bool IpcController::free() {
    cout<<"IpcController::free()"<<endl;
    if(shmctl(shmid, IPC_RMID, 0) == -1) {
        cout<<"free() shmctl failed"<<endl;
        return false;
    }
    return true;
}