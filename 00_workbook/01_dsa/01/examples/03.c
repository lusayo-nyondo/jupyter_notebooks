#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

int main() {
    clear_screen();
    int i, n, arr[20], smallest, smallest_index = 0;
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

    smallest = arr[0];
    smallest_index = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest_index = i;
        }
    }

    printf("\n The smallest element in the array = %d", smallest);
    printf("\n The index of the smallest element = %d\n", smallest_index);
    
    return 0;
}