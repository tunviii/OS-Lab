#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Create or modify an environment variable */
    setenv("MYVAR", "Operating Systems Lab", 1);

    /* Retrieve and display the environment variable */
    printf("Environment Variable MYVAR = %s\n", getenv("MYVAR"));

    return 0;
}
