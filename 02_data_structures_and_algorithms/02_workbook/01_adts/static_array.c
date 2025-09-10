#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int length;
    int *ptr;
} StaticArray;

StaticArray createStaticArray(int capacity, int length) {
    if (length > capacity) {
        return;
    }
}

int appendToStaticArray(StaticArray array, int element) {

}

int removeFromStaticArray(Static) {

}

int main() {
    int members[10];

    StaticArray arr = createStaticArray(
        20,
        5
    );
    
    return 0;
}