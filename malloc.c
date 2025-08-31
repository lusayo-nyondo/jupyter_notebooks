#include <stdio.h>
#include <stdlib.h>

int main() {
	int *x = malloc(sizeof(int));
	*x = 20;

	printf("%d, %p\n", *x, x);
	return 0;
}
