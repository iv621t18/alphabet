#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "lib.h"

void vvod() { 
    char mass1[255];
    for (int i = 0; i < 255; i++) {
    	mass1[i] = 0;
    }
    printf("%s\n", "Enter text:");
    __fpurge(stdin);
    fgets(mass1, 255, stdin);
    for (int i = 0; i < 255; i++) {
    	if (mass1[i] == '\n')
    		mass1[i] = '\0';
    }
    int l = strlen(mass1);
    char *str = separation(mass1, l);
    in_file(str);
}