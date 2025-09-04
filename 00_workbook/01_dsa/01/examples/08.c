#include <stdio.h>
#include <stdbool.h>

int get_insert_position(
    int value,
    int current_length,
    int capacity,
    int *array_ptr
) {
    int i;

    if (current_length >= capacity) {
        printf("Insert will fail because array is saturated.\n");
        return -1;
    }

    for (i = 0; i < current_length; i++) {
        if (array_ptr[i] > value) {
            return i;
        }
    }

    return current_length;
}

int insert_at(
    int position,
    int value,
    int *array_ptr,
    int current_length,
    int capacity
) {
    int i;

    if (current_length >= capacity) {
            printf("Can't insert into array because array is saturated\n");
            return -1;
    }

    if (position < 0 || position > current_length) {
        printf("Invalid insert position.");
        return -1;   
    }

    int value_to_insert = value;
    int temp = 0;

    for (i = position; i <= current_length; i++) {
        temp = array_ptr[i];
        array_ptr[i] = value_to_insert;
        value_to_insert = temp;
    }
}

int main() {
    int result, position, value_to_insert;
    int arr[20] = {
        2, 4, 6, 8, 10, 12, 14, 16
    };

    value_to_insert = 3;

    position = get_insert_position(
        value_to_insert,
        8,
        20,
        arr
    );

    if (position == -1) {
        return -1;
    }

    printf("Insert position is: %d\n", position);

    result = insert_at(
        position,
        value_to_insert,
        arr,
        8,
        20
    );
    if (result == -1) {
        return -1;
    }
    printf("Element inserted succesfully.\n New Array: ");

    for (int i = 0; i < 9; i++) {
        printf("%d", arr[i]);

        if (i < 8) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    return 0;
}