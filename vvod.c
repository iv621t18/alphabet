#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "lib.h"

int l1 = 0;
char mass1[255], x1[255], a1[255], b1[255];
bool p11 = true, p21 = false;
int kl1 = 0;

void sort1(bool var) {
    if((unsigned char)a1[0] > (unsigned char)b1[0]) {
        strcat(x1, b1);
        strcat(x1, " ");
        kl1++;
        if(var)
            strcat(x1, a1);
    } else {
        strcat(x1, a1);
        strcat(x1," ");
        if(var)
            strcat(x1, b1);
        else
            memcpy(a1, b1, 255);
    }
    if(var)
        memset(a1, (char)0, sizeof(a1));
    memset(b1, (char)0, sizeof(b1));
    if(var) {
        p21 = false;
        p11 = true;
    }
    else p21 = true;
}
 
void vvod() { 
    int n;
    printf("%s\n", "Vvedite text");
    __fpurge(stdin);
    fgets(mass1, 255, stdin);
    l1 = strlen(mass1);
    do {
        kl1 = 0;
        for (n=0; n<l1; n++) {
            if (p11 && mass1[n] != ' ') {
                strncat(a1, &mass1[n], 1);
            }
            else if (p11 && a1[0] != 0 && mass1[n+1] != ' ' && mass1[n] == ' ') {
                p21 = true;
                p11 = false;
                continue;
            }
            else if (p21 && mass1[n] != ' ') {
                strncat(b1, &mass1[n], 1);
            }
            else if (mass1[n] == ' ' && mass1[n+1] != ' ' && p21) {
                p21 = false;
            }
            if ((!p21 && !p11) || (n == l1-1)) {
                if (n == l1-1)
                    sort1(1);
                else
                    sort1(0);
            }
        }
    memcpy(mass1, x1, 255);
    memset(x1, (char)0, sizeof(x1));
    } while (kl1 != 0);


    FILE* itog;
    itog = fopen("itog.txt", "w");
    fwrite(&mass1,  sizeof(mass1),  1,  itog);
    fclose(itog);


    printf("\nResult:\n%s", mass1);
}
