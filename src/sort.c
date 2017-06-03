#include <stdlib.h>
#include <string.h>
#include "sort.h"

static int cmpstringp(const void *p1, const void *p2)
{
   return strcmp(*(char* const*)p1, *(char* const*)p2);
}

char **sort(char **str, int count)
{
	if (str == NULL) {
		return NULL;
	}
	qsort(str, count, sizeof(char*), cmpstringp);
	return str;
}
