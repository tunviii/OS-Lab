#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *rd;
    char buffer[50];

    rd = popen("ls", "r");

    fread(buffer, sizeof(char), 40, rd);

    printf("%s", buffer);

    pclose(rd);

    return 0;
}
