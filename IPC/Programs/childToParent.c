#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int fd[2], n;
    char buffer[100];
    pid_t p;

    pipe(fd);
    p = fork();

    if(p > 0){
        printf("Parent received data\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
    else{
        printf("Child sending data\n");
        write(fd[1], "OS Lab\n", 7);
    }
}
