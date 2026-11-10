#include <stdio.h>
int fork[5] = {1};
int eating[5] = {0};
int mutex = 1;
void wait(int *S)
{
    while (*S <= 0);
    (*S)--;
}
void signal(int *S)
{
    (*S)++;
}
void philosopher(int i)
{
    int left = i;
    int right = (i + 1) % 5;
    wait(&mutex);
    if (fork[left] == 1 && fork[right] == 1)
    {
        fork[left] = 0;
        fork[right] = 0;
        eating[i] = 1;
        printf("Philosopher %d is eating.\n", i + 1);
    }
    else
    {
        printf("Philosopher %d cannot eat. Forks unavailable!\n",
               i + 1);
    }
    signal(&mutex);
}
void finish(int i)
{
    wait(&mutex);
    if (eating[i])
    {
        fork[i] = 1;
        fork[(i + 1) % 5] = 1;
        eating[i] = 0;
        printf("Philosopher %d finished eating.\n", i + 1);
    }
    else
    {
        printf("Philosopher %d is not eating!\n", i + 1);
    }
    signal(&mutex);
}
int main()
{
    int choice, p;
    while (1)
    {
        printf("\n1. Start eating\n");
        printf("2. Finish eating\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 0)
            return 0;
        if (choice != 1 && choice != 2)
        {
            printf("Invalid choice!\n");
            continue;
        }
        printf("Enter philosopher number (1-5): ");
        scanf("%d", &p);
        if (p < 1 || p > 5)
        {
            printf("Invalid philosopher number!\n");
            continue;
        }
        if (choice == 1)
            philosopher(p - 1);
        else
            finish(p - 1);
    }
}
