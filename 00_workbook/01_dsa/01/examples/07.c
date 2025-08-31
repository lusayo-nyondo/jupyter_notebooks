/**
 * A program to insert an element at a given position in an array.
 */
#include <stdio.h>
#include <stdlib.h>

int insert_at(
    int position,
    int value,
    int current_length,
    int total_capacity,
    int *array
) {
    if (current_length >= total_capacity) {
        printf("Array is saturated.\n");
        return -1;
    }

    if (position < 0 || position >= current_length) {
        printf("Array position is invalid.\n");
        return -1;
    }

    for (int i = current_length - 1; i > position; i--) {
        array[i + i] = array[i];
    }

    array[position] = value;

    return 0;
}

int main() {
    int array[20] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };

    int result = insert_at(5, 20, 8, 20, array);

    if (result == -1) {
        printf("Failed to insert into array.");
        return -1;
    }
    for (int i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
