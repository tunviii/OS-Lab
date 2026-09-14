#include <stdio.h>
#include <string.h>

int main() {
    FILE *rd;
    char buffer[50];

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    rd = popen("wc -c", "w");

    fwrite(buffer, sizeof(char), strlen(buffer), rd);

    pclose(rd);

    return 0;
}
