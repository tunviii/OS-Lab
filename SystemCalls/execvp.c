#include <unistd.h>
int execvp(const char *file, char *const argv[]);
#include <stdio.h>
#include <unistd.h>
=====
int main()
{
    char *args[] = {"ls", "-l", NULL};

    printf("Before execvp()\n");

    execvp("ls", args);

    // Executes only if execvp() fails
    printf("execvp() failed.\n");

    return 0;
}
