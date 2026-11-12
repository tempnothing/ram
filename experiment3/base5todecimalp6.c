#include <stdio.h>

int main(void) {
    int n, decimal = 0, power = 1, digit, valid = 1;
    printf("Enter a base 5 number: ");
    scanf("%d", &n);
    while (n > 0) {
        digit = n % 10;
        if (digit > 4) valid = 0;
        decimal += digit * power;
        power *= 5;
        n /= 10;
    }
    if (valid) printf("Decimal number: %d\n", decimal);
    else printf("Invalid base 5 number\n");
    return 0;
}
