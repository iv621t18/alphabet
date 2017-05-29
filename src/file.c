#include <string.h>
#include <stdio_ext.h>
#include "lib.h"

void file() { 	
    char mass[255];
    for (int i = 0; i < 255; i++) {
    	mass[i] = 0;
    }
    FILE *text = fopen("text.txt", "r");
    
    fgets(mass, 255, text);
    
    for (int i = 0; i < 255; i++) {
        if (mass[i] == '\n') {
            mass[i] = '\0';
        }
    }

	int l = strlen(mass);

	char *str = separation(mass, l);
    in_file(str);
    fclose(text);
}