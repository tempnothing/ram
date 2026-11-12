#include <stdio.h>

int main(void) {
    int n, bits[sizeof(int) * 8], count = 0, i;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if (n == 0) { printf("Binary number: 0\n"); return 0; }
    while (n > 0) { bits[count++] = n % 2; n /= 2; }
    printf("Binary number: ");
    for (i = count - 1; i >= 0; i--) printf("%d", bits[i]);
    putchar('\n');
    return 0;
}
