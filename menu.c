#include "lib.h"
#include <stdio.h>
#include <stdbool.h>

void menu() {
    int x = 0;
    printf("%s\n", "1. Ввести текст самому");
    printf("%s\n", "2. Загрузить текст из файла");
    scanf("%d", &x);
    if (x == 1)
        vvod();
    else if (x == 2)
        file();
    else 
        printf("%s", "Ошибка. Выберите 1 или 2\n");
}
