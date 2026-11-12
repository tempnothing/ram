#include <stdio.h>
#include <stdlib.h>
 
struct Block {
    int number;
    struct Block *next;
};
 
int main() {
    struct Block *head = NULL, *tail = NULL, *p;
    int n, i, x;
 
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
 
        p = malloc(sizeof(struct Block));
        p->number = x;
        p->next = NULL;
 
        if (head == NULL)
            head = p;
        else
            tail->next = p;
 
        tail = p;
    }
 
    for (p = head; p != NULL; p = p->next)
        printf("%d -> ", p->number);
 
    printf("NULL\n");
 
    while (head != NULL) {
        p = head;
        head = head->next;
        free(p);
    }
 
    return 0;
}
