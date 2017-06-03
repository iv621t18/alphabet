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
