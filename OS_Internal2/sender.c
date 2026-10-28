#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = 1234;
    int shmid;
    char *shared_memory;

    // Create shared memory segment
    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory
    shared_memory = (char *)shmat(shmid, NULL, 0);

    if (shared_memory == (char *)-1) {
        perror("shmat");
        exit(1);
    }

    // Write message
    printf("Enter a message: ");
    fgets(shared_memory, 1024, stdin);

    printf("Message written to shared memory.\n");

    // Detach shared memory
    shmdt(shared_memory);

    return 0;
}
