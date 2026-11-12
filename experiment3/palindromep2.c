#include <stdio.h>

int main(void) {
    int n, temp, rev = 0, digit;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n > 0) { digit = n % 10; rev = rev * 10 + digit; n /= 10; }
    printf(temp == rev ? "Palindrome\n" : "Not Palindrome\n");
    return 0;
}
