#include <stdio.h>

int main(void) {
    int n, digits[sizeof(int) * 8], count = 0, i;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    if (n == 0) { printf("Base 5 number: 0\n"); return 0; }
    while (n > 0) { digits[count++] = n % 5; n /= 5; }
    printf("Base 5 number: ");
    for (i = count - 1; i >= 0; i--) printf("%d", digits[i]);
    putchar('\n');
    return 0;
}
