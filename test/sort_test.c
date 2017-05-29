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

CTEST(sort, sort_2)
{
	char real[] = "1 2 3";
	char test[] = "2 3 1";

	char *str = separation(test, strlen(test));

	ASSERT_STR(str, real);
}

CTEST(sort, sort_3)
{
	char real[] = "ab aa ca";
	char test[] = "ca ab aa";

	char *str = separation(test, strlen(test));

	ASSERT_STR(str, real);
}

CTEST(sort, sort_4)
{
	char real[] = "21 7 aaa bs";
	char test[] = "bs aaa 7 21";

	char *str = separation(test, strlen(test));

	ASSERT_STR(str, real);
}
