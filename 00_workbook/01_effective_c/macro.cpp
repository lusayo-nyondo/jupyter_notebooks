#include <stdio.h>
#include <stdlib.h>
#include <string>

#define ADD(x, y) (x) + (y)

using namespace std;

int main() {
	string hello_world = ADD(string("Hello"), string(" World"));
	printf("%s\n", hello_world.c_str());
	return 0;
}
