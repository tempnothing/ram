#include <stdio.h>
 
int main()
{
    int n, i, time = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float avg1 = 0, avg2 = 0;
 
    printf("Enter number of processes: ");
    scanf("%d", &n);
 
    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT: ");
        scanf("%d%d", &at[i], &bt[i]);
    }
 
    for(i = 0; i < n; i++)
    {
        if(time < at[i])
            time = at[i];
 
        time = time + bt[i];
        ct[i] = time;
 
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
 
        avg1 += tat[i];
        avg2 += wt[i];
    }
 
    printf("\nP\tCT\tTAT\tWT\n");
 
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, ct[i], tat[i], wt[i]);
 
    printf("Average TAT = %.2f\n", avg1/n);
    printf("Average WT = %.2f\n", avg2/n);
 
    return 0;
}
