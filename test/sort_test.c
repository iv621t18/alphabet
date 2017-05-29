#include <ctest.h>
#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(sort, sort_1)
{
	char real[] = "a b c";
	char test[] = "c b a";

	char *str = separation(test, strlen(test));

	ASSERT_STR(str, real);
}