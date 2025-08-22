#include <stdio.h>
#include <stdlib.h>

int* getInt() {
	int* x = (int*)malloc(sizeof(int));
	*x = 2;
	return x;
}

int main() {
	printf("%d\n", *getInt());
	return 0;
}
