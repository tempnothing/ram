#include <stdio.h>
#define MAX 50
 
struct Disk {
    int block[MAX];
};
 
int main() {
    struct Disk d = {{0}};
    int start, n, i, free = 1;
 
    scanf("%d%d", &start, &n);
 
    for (i = start; i < start + n; i++)
        if (d.block[i]) free = 0;
 
    if (free) {
        for (i = start; i < start + n; i++)
            d.block[i] = 1;
 
        printf("Allocated: ");
        for (i = start; i < start + n; i++)
            printf("%d ", i);
    } else {
        printf("Allocation failed");
    }
 
    return 0;
}
