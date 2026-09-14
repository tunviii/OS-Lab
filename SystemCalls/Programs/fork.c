#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
pid_t p;
printf("before fork\n");
p=fork();
if(p==0){
printf("Child having pid: %d\n", getpid());
printf("Parent having pid: %d\n", getppid());
}
else{
printf("Parent pid: %d\n", getpid());
printf("Child pid: %d\n", p);
}
return 0;
}
