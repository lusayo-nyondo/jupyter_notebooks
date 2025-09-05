#include <stdio.h>;
#include <stdlib.h>;

typedef struct {
    int length;
    int *elements;
} StaticArray;

typedef void (*ForEachFunction)(int element, int index);

void print_element_and_index(int element, int index) {
    printf("Element at index %d is: %d\n", index, element);
}

StaticArray* sa_create(int length) {
    StaticArray* array = malloc(sizeof(StaticArray));
    array->elements = malloc(length * sizeof(int));

    if (array == NULL) {
        return NULL;
    }

    if (array->elements == NULL) {
        free(array);
        return NULL;
    }

    array->length = length;

    return array;
}

int sa_get_at(StaticArray* array, int position) {
    if (position < 0 || position >= array->length) {
        return NULL;
    }

    return array->elements[position];
}

int sa_set_at(StaticArray* array, int position, int value) {
    if (position < 0 || position >= array->length) {
        return NULL;
    }

    array->elements[position] = value;

    return 0;
}

void sa_for_each(StaticArray* array, ForEachFunction function) {
    if (array == NULL || function == NULL) {
        return NULL;
    }

    for (int i = 0; i < array->length; i++) {
        function(array->elements[i], i);
    }
}

void sa_destroy(StaticArray* array) {
    if (array == NULL) return;
    free(array->elements);
    free(array);
}

int main() {
    StaticArray* arr = sa_create(20);
    if (arr == NULL) {
        fprintf(stderr, "Failed to create array.\n");
        return 1;
    }

    for (int i = 0; i < arr->length; i++) {
        sa_set_at(arr, i, i * 2);
    }
    
    sa_for_each(arr, print_element_and_index);
    sa_destroy(arr);
    
    return 0;
}
