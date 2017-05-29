#include <string.h>
#include <stdio_ext.h>
#include "lib.h"

void in_file(char *mass1)
{
    FILE* itog;
    itog = fopen("itog.txt", "w");
    fprintf(itog, "%s", mass1);
    fclose(itog);
    printf("\nResult: %s", mass1);
    printf("\n");
}

int sort1(int var, char *word1, char *word2, char *rez, int *kl, int *p2, int *p1, int l)
{
    if((unsigned char)word1[0] > (unsigned char)word2[0]){
        strcat(rez, word2);
        strcat(rez, " ");
        *kl = 1;
        if(var == 1)
            strcat(rez, word1);
        } else {
            strcat(rez, word1);
            strcat(rez, " ");
            if(var == 1) {
                strcat(rez, word2);
            }
            else {
                word1[0] = '\0';
                strcat(word1, word2);
            }
        }
        if(var == 1)
            word1[0] = '\0';
            word2[0] = '\0';
        if(var == 1) {
            *p2 = 0;
            *p1 = 1;
        }
    else 
    *p2 = 1;
    return 0;
}

char *separation(char *mass1, int l) 
{
    int kl = 0, p1 = 1, p2 = 0; //ключи
    int y = 1; //флаг конца файла
    int z = 0; //флаг не конца файла
    char rez[255], word1[255], word2[255];
    for (int i = 0; i < 255; i++) {
        rez[i] = 0;
        word1[i] = 0;
        word2[i] = 0;
    }
    do {
     	kl = 0;
        for(int n = 0; n < l; n++) {
            if(p1 == 1 && mass1[n] != ' ') {
            strncat(word1, &mass1[n], 1);
        } else if (p1 == 1 && word1[0] != 0 && mass1[n+1] != ' ' && mass1[n] == ' ') {
            p2 = 1;
            p1 = 0;
            continue;
        } else if (p2 == 1 && mass1[n] != ' ') {
            strncat(word2, &mass1[n], 1);
        } else if (mass1[n] == ' ' && mass1[n+1] != ' ' && p2 == 1) {
            p2 = 0;
        }
        if((p2 == 0 && p1 == 0) || (n == l-1)) {
            if(n == l-1) {
                sort1(y, word1, word2, rez, &kl, &p2, &p1, l);
            } else {
                sort1(z, word1, word2, rez, &kl, &p2, &p1, l);
            }
        }
        }
        mass1[0] = '\0';
        strcat(mass1, rez);
        rez[0] = '\0';
    } while(kl != 0);
    return mass1;
}

