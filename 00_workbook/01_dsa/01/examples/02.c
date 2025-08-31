#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

int main() {
    clear_screen();
    int i, n, arr[20], sum = 0;
    float mean = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\narr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    mean = (float)sum / n;
    printf("\n The sum of the array elements = %d", sum);
    printf("\n The mean of the array elements = %.2f\n", mean);
    
    return 0;
}