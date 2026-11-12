#include <stdio.h>

int main(void) {
    int n, temp, sum = 0, digit;
    printf("Enter a three-digit number: ");
    scanf("%d", &n);
    temp = n;
    while (n > 0) { digit = n % 10; sum += digit * digit * digit; n /= 10; }
    printf(temp == sum ? "Armstrong Number\n" : "Not Armstrong Number\n");
    return 0;
}
