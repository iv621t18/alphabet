#include "lib.h"
#include <stdio.h>
#include <stdbool.h>

void menu()
{
	int x = 0;
	printf("%s\n", "1.Ввод");
	printf("%s\n", "2.Файл");
	scanf("%d", &x);
	if 
		(x == 1)
		vvod();
	else{
		if (x == 2)
		file();
	else 
    		printf("%s", "Неверные данные");}
}
