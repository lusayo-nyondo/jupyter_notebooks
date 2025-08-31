#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

int main() {
    clear_screen();
    int i, n, arr[20], largest, second_largest = 0;
    float mean = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nNumber entered is too small. Must be greater than 0.");
        return -1;
    }

    for (i = 0; i < n; i++) {
        printf("\narr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    largest = arr[0];
    second_largest = largest;

    for (i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }

        if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
    }

    printf("\n The largest element in the array = %d", largest);
    printf("\n The second largest element = %d\n", second_largest);
    
    return 0;
}