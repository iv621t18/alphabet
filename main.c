#include <stdio.h>
#include <string.h>
#include <sys/types.h>//Консанты
#include <sys/stat.h>//Прототип chmod
#include <unistd.h>//Прототип access
#include <stdlib.h>

#define MAX_NUM_STR 512
#define MAX_LEN_STR 256

int main (int argc, char* argv[])
{
	if (argc == 1 || argc > 2) {
		printf("Too few arguments\nUsage: alphabet <input_file>\n");
		return 1;
	}

	if (access(argv[1], 0) == 0) {
		if (access(argv[1], 4) != 0) {
			if (chmod(argv[1], S_IREAD) != 0) {
				perror(NULL);
				return 1;
			}
		}
	} else {
		perror(NULL);
		return 1;
	}

	FILE *in = fopen(argv[1], "r");
	if (in == NULL) {
		printf("Usage: alphabet <input_file>\n");
		return 1;
	}

	char **str = calloc(MAX_NUM_STR, sizeof(char*));
	if (str == NULL) {
		printf("SIGSEGV\n");
		return 1;
	}
	int count = 0;
	for (int i = 0; !feof(in); i++) {
		str[i] = malloc(sizeof(char) * MAX_LEN_STR);
		if (str[i] == NULL) {
			printf("SIGSEGV\n");
			return 1;
		}
		fgets(str[i], MAX_LEN_STR, in);
		str[i][strlen(str[i]) - 1] = '\0';
		if (str[i][0] == '\0') {
			i--;
			continue;
		}
		count++;
	}

	fclose(in);
	return 0;
}
