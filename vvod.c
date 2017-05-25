#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "lib.h"

void vvod()
{ 
	char mass1[255];
	printf("%s\n","Vvedite text");
	__fpurge(stdin);
	fgets(mass1,255,stdin);
	int l=strlen(mass1);
	razdelenie(mass1,l);

}






