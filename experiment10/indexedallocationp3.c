#include <stdio.h>
#define MAX 50
 
struct IndexBlock {
    int number;
    int data[MAX];
    int count;
};
 
int main() {
    struct IndexBlock idx;
    int i;
 
    scanf("%d%d", &idx.number, &idx.count);
 
    for (i = 0; i < idx.count; i++)
        scanf("%d", &idx.data[i]);
 
    printf("Index block: %d\n", idx.number);
    printf("Data blocks: ");
 
    for (i = 0; i < idx.count; i++)
        printf("%d ", idx.data[i]);
 
    return 0;
}
