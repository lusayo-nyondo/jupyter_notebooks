#include <stdio.h>

int* getInt() {
	int x = 2;
	return &x;
}

int main() {
	printf("%p\n", getInt());
	return 0;
}
