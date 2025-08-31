/**
 * A program to insert an element at a given position in an array.
 */
#include <stdio.h>
#include <stdlib.h>

void insert_at(int position, int value, int *array, int new_length) {
    int temp = 0;

    for(int i = position; i < new_length; i++) {
        temp = *(array + i + 1);
        *(array + i + 1) = *(array + i);
        *(array + i) = temp;
    }

    array[position] = value;
}

int main() {
    int array[20] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };

    insert_at(5, 20, array, 9);

    for (int i = 0; i < 9; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}
