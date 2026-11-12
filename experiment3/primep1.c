#include <stdio.h>

int main(void) {
    int n, i, is_prime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 1) is_prime = 0;
    for (i = 2; is_prime && i * i <= n; i++)
        if (n % i == 0) is_prime = 0;
    printf(is_prime ? "Prime\n" : "Not Prime\n");
    return 0;
}
