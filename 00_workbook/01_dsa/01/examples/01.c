#include <stdio.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

int main() {
    int i, n, arr[20];

    clear_screen();
    printf("\n Enter the number of elements in the array: ");

    scanf("%d", &n);

    for (i = 0; i < n; i ++) {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n The array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
