#include <stdio.h>

int main() {
    int nums[10];
    
    for (int i = 0; i < 10; i++) {
        int n = scanf("Enter number: \n");
        nums[i] = n;
    }

    for (int i = 0; i < 10; i++) {
        if (i % 3 != 2) {
            printf("%d, ", nums[i]);
        } else {
            printf("%d\n", nums[i]);
        }
    }
}