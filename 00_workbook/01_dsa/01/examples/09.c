#include <stdio.h>

int delete_from_array(
    int position,
    int *array,
    int current_length,
    int capacity
) {
    int i = 0;

    if (current_length == capacity) {
        printf("Current length can't be greater than capacity.");
        return -1;
    }

    if (position < 0 || position >= current_length) {
        printf("Invalid delete position");
        return -1;
    }

    for (i = position; i < current_length - 1; i++) {
        array[i] = array[i + 1];
    }

    return 0;
}

int main() {
    int i, result = 0;
    int arr[20] = {
        2, 4, 6, 8, 10, 12, 14, 16
    };

    result = delete_from_array(3, arr, 8, 20);

    if (result == -1) {
        return -1;
    }

    for (i = 0; i < 7; i++) {
        printf("%d", arr[i]);

        if (i < 6) {
            printf(", ");
        }
    }

    printf("\n");
}