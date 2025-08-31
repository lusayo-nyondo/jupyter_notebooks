#include <stdio.h>
#include <math.h>

int main() {
    int number, digit[10], num_digits, i;

    printf("\n Enter the number of digits: ");
    scanf("%d", &num_digits);

    for (i = 0; i < num_digits; i++) {
        printf("\n Enter the digit at position %d: ", i + 1);
        scanf("%d", &digit[i]);
    }

    i = num_digits - 1;

    while (i >= 0) {
        number = number + digit[i] * pow(10, i);
        i--;
    }

    printf("\n The number is: %d\n", number);
    return 0;
}