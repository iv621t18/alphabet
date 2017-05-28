#include <string.h>
#include <stdio_ext.h>
#include "lib.h"

void in_file(char *mass1)
{
    FILE* itog;
    itog = fopen("itog.txt", "w");
    fwrite(&mass1, sizeof(mass1), 1, itog);
    fclose(itog);
    printf("\nResult:\n%s", mass1);
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
        if(var == 1)
            strcat(rez, word2);
        else
            memcpy(word1, word2, 255);
    }
        if(var == 1)
            memset(word1, (char)0, l);
        memset(word2, (char)0, l);
        if(var == 1) {
            *p2 = 0;
            *p1 = 1;
        }
        else 
            *p2 = 1;
    return 0;
}

int separation(char *mass1, int l) 
{
    int kl = 0, p1 = 1, p2 = 0; //ключи
    int y = 1; //флаг конца файла
    int z = 0; //флаг не конца файла
    char rez[255], word1[255], word2[255];
    do {
 	    kl = 0;
        for(int n = 0; n < l; n++) {
            if(p1 == 1 && mass1[n] != ' ') {
                strncat(word1, &mass1[n], 1);
            }
            else if(p1 == 1 && word1[0] != 0 && mass1[n+1] != ' ' && mass1[n] == ' ') {
                p2 = 1;
                p1 = 0;
                continue;
            }
            else if(p2 == 1 && mass1[n] != ' ') {
                strncat(word2, &mass1[n], 1);
            }
            else if(mass1[n] == ' ' && mass1[n+1] != ' ' && p2 == 1) {
                p2 = 0;
            }
            if((p2 == 0 && p1 == 0) || (n == l-1)) {
                if(n == l-1)
                    sort1(y, word1, word2, rez, &kl, &p2, &p1, l);
                else sort1(z, word1, word2, rez, &kl, &p2, &p1, l);
            }
        }
    memcpy(mass1, rez, 255);
    memset(rez, (char)0, sizeof(rez));
    } while(kl != 0);

    in_file(mass1);
    return 0;
}

