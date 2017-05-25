#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "lib.h"

void file()
{ 	char mass[255];
char mas[255];
	FILE *text;
	int n;
	text=fopen("text.txt","r");
	if(fgets(mass,255, text)!=NULL)
	mass[strlen(mass)-1]=0;
	int l=strlen(mass);
	razdelenie(mass,l);

}

