#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
int n, fd;

char buff [50];

fd=open("test.txt", O_RDONLY);
printf("File descriptor: %d", fd);
n=read(fd, buff, 10);
write(1, buff, n);
}
