#include <sort.h>
#include <ctest.h>
#include <stdlib.h>

CTEST(SORT_TEST, COMMON)
{
	char *exp[] = {"aborigen", "borginore", "array", "Huston", "ALEOP"};

	sort(exp, 5);

	char *real[] = {"ALEOP", "Huston", "aborigen", "array", "borginore"};

	for (int i = 0; i < 5; i++) {
		ASSERT_STR(exp[i], real[i]);
	}
}

CTEST(SORT_TEST, ARRAY_IS_EMPTY)
{
	char **exp = calloc(1, sizeof(char*));

	exp = sort(exp, 0);

	ASSERT_STR(exp[0], 0);
}

CTEST(SORT_TEST, ARRAY_IS_NULL)
{
	char **exp = sort(NULL, 5);

	ASSERT_NULL(exp);
}

CTEST(SORT_TEST, DIGITAL_TEST)
{
	char *exp[] = {"10", "9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};

	sort(exp, 11);

	char *real[] = {"0", "1", "10", "2", "3", "4", "5", "6", "7", "8", "9"};

	for (int i = 0; i < 11; i++) {
		ASSERT_STR(exp[i], real[i]);
	}
}
