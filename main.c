#include <stdio.h>

int main (int argc, char* argv[])
{
	if (argc == 1 || argc > 2) {
		printf("Too few arguments\nUsage: alphabet <input_file>\n");
		return 1;
	}
	return 0;
}
