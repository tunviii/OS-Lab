#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    struct stat file;

    if (stat("sample.txt", &file) == 0)
    {
        printf("File Size : %ld bytes\n", file.st_size);
        printf("Inode Number : %ld\n", file.st_ino);
        printf("Number of Links : %ld\n", file.st_nlink);
        printf("User ID : %d\n", file.st_uid);
        printf("Group ID : %d\n", file.st_gid);
    }
    else
    {
        printf("Unable to access file.\n");
    }

    return 0;
    }
