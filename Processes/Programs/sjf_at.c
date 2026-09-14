#include <stdio.h> 
 
int main() 
{ 
    int n, i, j, time = 0, completed = 0; 
    int at[10], bt[10], wt[10], tat[10], ct[10]; 
    int isCompleted[10] = {0}; 
    float avgWT = 0, avgTAT = 0; 
 
    printf("Enter number of processes: "); 
    scanf("%d", &n); 
 
    printf("Enter Arrival Time and Burst Time:\n"); 
 
    for(i = 0; i < n; i++) 
    { 
        printf("P%d Arrival Time: ", i + 1); 
        scanf("%d", &at[i]); 
 
        printf("P%d Burst Time: ", i + 1); 
        scanf("%d", &bt[i]); 
    } 
 
    while(completed < n) 
    { 
        int shortest = -1; 
        int minBT = 9999; 
 
        // Find the shortest job among arrived processes 
        for(i = 0; i < n; i++) 
        { 
            if(at[i] <= time && isCompleted[i] == 0) 
            { 
                if(bt[i] < minBT) 
                { 
                    minBT = bt[i]; 
                    shortest = i; 
                } 
            } 
        } 
 
        // If no process has arrived yet 
        if(shortest == -1) 
        { 
            time++; 
        } 
        else 
        { 
            // Execute the selected process 
            time = time + bt[shortest]; 
 
            ct[shortest] = time; 
            tat[shortest] = ct[shortest] - at[shortest]; 
            wt[shortest] = tat[shortest] - bt[shortest]; 
 
            avgWT += wt[shortest]; 
            avgTAT += tat[shortest]; 
 
            isCompleted[shortest] = 1; 
            completed++; 
        } 
    } 
 
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n"); 
 
    for(i = 0; i < n; i++) 
    { 
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", 
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]); 
    } 
 
    printf("\nAverage Waiting Time = %.2f", avgWT / n); 
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n); 
 
    return 0; 
}