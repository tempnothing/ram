#include <stdio.h>
 
int main()
{
    int pages[50], frames[10], last[10];
    int n, f, i, j, found, pos;
    int faults = 0, hits = 0;
 
    printf("Enter number of pages: ");
    scanf("%d", &n);
 
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
 
    printf("Enter number of frames: ");
    scanf("%d", &f);
 
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        last[i] = -1;
    }
 
    for(i = 0; i < n; i++)
    {
        found = 0;
 
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                last[j] = i;
                break;
            }
        }
 
        if(found)
            hits++;
        else
        {
            faults++;
            pos = 0;
 
            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
 
                if(last[j] < last[pos])
                    pos = j;
            }
 
            frames[pos] = pages[i];
            last[pos] = i;
        }
 
        printf("\n%d\t", pages[i]);
 
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
 
        if(found)
            printf("Hit");
        else
            printf("Page Fault");
    }
 
    printf("\n\nPage Faults = %d", faults);
    printf("\nPage Hits = %d\n", hits);
 
    return 0;
}
