#include <stdio.h>

int main() {
	int x = 5;
	int& ref_x = x;
	
	ref_x = 10;

	printf("%d", x);
	return 0;
}
