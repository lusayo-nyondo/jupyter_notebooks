#include <stdio.h>
#include <stdbool.h>

void clear_screen() {
    printf("\033[2J\033[H");
}

typedef struct {
    int num;
    int count;
} CountMap;

CountMap* get_key(int key, CountMap *counts, int n) {
    for (int i = 0; i < n; i++) {
        CountMap *current = (counts + i);
        if (current -> num == key) {
            return current;
        } 
    }

    return NULL;
}

int main() {
    clear_screen();
    int i, n = 0;
    int arr[20];
    CountMap counts[20];
    
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

    int counts_n = 0;

    for (i = 0; i < n; i++) {
        CountMap *current = get_key(arr[i], counts, counts_n);
        
        if (current == NULL) {
            CountMap new;
            new.num = arr[i];
            new.count = 1;

            counts[counts_n] = new;
            counts_n += 1;
        } else {
            current -> count += 1;
        }
    }

    for (int i = 0; i < counts_n; i++) {
        CountMap current = counts[i];

        if (current.count > 1) {
            printf("Detected a duplicate: %d\n", current.num);
            return -1;
        }
    }

    printf("No duplicates detected.\n"); 
    return 0;
}
