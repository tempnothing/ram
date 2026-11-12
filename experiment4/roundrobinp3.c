#include <stdio.h>
 
int main()
{
    int n, i, time, q, count = 0;
    int at[20], bt[20], rem[20], ct[20], tat[20], wt[20];
    int queue[20], front = 0, rear = 0, size = 0;
    int next = 0, pos, run;
    float avg1 = 0, avg2 = 0;
 
    printf("Enter number of processes: ");
    scanf("%d", &n);
 
    for(i = 0; i < n; i++)
    {
        printf("Enter AT and BT: ");
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }
 
    printf("Enter Time Quantum: ");
    scanf("%d", &q);
 
    time = at[0];
 
    while(next < n && at[next] <= time)
    {
        queue[rear] = next;
        rear = (rear + 1) % 20;
        size++;
        next++;
    }
 
    while(count < n)
    {
        if(size == 0)
        {
            time = at[next];
 
            while(next < n && at[next] <= time)
            {
                queue[rear] = next;
                rear = (rear + 1) % 20;
                size++;
                next++;
            }
        }
 
        pos = queue[front];
        front = (front + 1) % 20;
        size--;
 
        if(rem[pos] > q)
            run = q;
        else
            run = rem[pos];
 
        time += run;
        rem[pos] -= run;
 
        while(next < n && at[next] <= time)
        {
            queue[rear] = next;
            rear = (rear + 1) % 20;
            size++;
            next++;
        }
 
        if(rem[pos] > 0)
        {
            queue[rear] = pos;
            rear = (rear + 1) % 20;
            size++;
        }
        else
        {
            ct[pos] = time;
            count++;
        }
    }
 
    printf("\nP\tCT\tTAT\tWT\n");
 
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
 
        printf("P%d\t%d\t%d\t%d\n", i+1, ct[i], tat[i], wt[i]);
 
        avg1 += tat[i];
        avg2 += wt[i];
    }
 
    printf("Average TAT = %.2f\n", avg1/n);
    printf("Average WT = %.2f\n", avg2/n);
 
    return 0;
}
