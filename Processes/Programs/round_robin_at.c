#include <stdio.h>

#define MAX 10

int main()
{
    int n, i;
    int at[MAX], bt[MAX], rt[MAX];
    int ct[MAX], tat[MAX], wt[MAX];
    int queue[MAX * 10];
    int front = 0, rear = 0;
    int time = 0, completed = 0;
    int qt;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &qt);

    // Add processes arriving at time 0
    for(i = 0; i < n; i++)
    {
        if(at[i] == 0)
            queue[rear++] = i;
    }

    while(completed < n)
    {
        // If ready queue is empty, move time forward
        if(front == rear)
        {
            time++;

            for(i = 0; i < n; i++)
            {
                if(at[i] == time)
                    queue[rear++] = i;
            }

            continue;
        }

        int current = queue[front++];

        // Execute process for time quantum or remaining burst time
        if(rt[current] > qt)
        {
            rt[current] -= qt;
            time += qt;

            // Add processes that arrived during execution
            for(i = 0; i < n; i++)
            {
                if(at[i] > time - qt && at[i] <= time)
                    queue[rear++] = i;
            }

            // Add current process back to queue
            queue[rear++] = current;
        }
        else
        {
            time += rt[current];
            rt[current] = 0;

            ct[current] = time;
            tat[current] = ct[current] - at[current];
            wt[current] = tat[current] - bt[current];

            completed++;

            // Add processes that arrived during execution
            for(i = 0; i < n; i++)
            {
                if(at[i] > time - bt[current] && at[i] <= time)
                    queue[rear++] = i;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        avgWT += wt[i];
        avgTAT += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}