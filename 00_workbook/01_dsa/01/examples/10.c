#include <stdio.h>

int get_position_of(
    int value,
    int *array,
    int current_length,
    int capacity
) {
    int i;

    if (current_length > capacity) {
        printf("Invalid. Current length cannot be greater than capacity.");
        return -1;
    }

    for (i = 0; i < current_length; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return current_length;
}

void delete_from_array(
    int position,
    int *array,
    int current_length,
    int capacity
) {
    if (position < 0 || position > current_length) {
        printf("Invalid position.\n");
    }

    if (current_length > capacity) {
        printf("Invalid. Current length cannot be greater than capacity.\n");
        return -1;
    }

    int i = 0;
    for (i = position; i < current_length - 1; i++) {
        array[i] = array[i + 1];
    }
}

int main() {
    int array[20] = {
        2, 4, 6, 8, 10, 12, 14, 16
    };

    

    return 0;
}