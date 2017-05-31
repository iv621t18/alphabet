#include <stdlib.h>
#include <stdio.h>
#include<string.h>

char abc[]={'c','b','a','\0'};

static int
comp(const void *word1, const void *word2){

	return strcmp(word1, word2);

}
int main(){

	qsort(&abc,4,sizeof(char*),comp);
	for (int j = 0; j < 4; j++)
		printf("%d\n",abc[j]);

	return 0;
}
