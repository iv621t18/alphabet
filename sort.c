#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>
#include "lib.h"

void in_file(char *x1)
{
	FILE* itog;
	itog=fopen("itog.txt","w");
	fwrite(&x1,sizeof(x1),1,itog);
	fclose(itog);
	printf("\nResult:\n%s",x1);
}

int sort1(int var,char *a1, char *b1, char *x1,int *kl1,int *p21,int *p11,int l)
{
	if((unsigned char)a1[0]>(unsigned char)b1[0]){
 			strcat(x1,b1);
 			strcat(x1," ");
 			*kl1=1;
 		if(var==1)
   			 strcat(x1,a1);
		}
		else{
 			strcat(x1,a1);
 			strcat(x1," ");
 		if(var==1)
   			 strcat(x1,b1);
 		else
   			 memcpy(a1,b1,255);
}
		if(var==1)
 			memset(a1,(char)0,l);
			memset(b1,(char)0,l);
		if(var==1){
			*p21=0;
 			*p11=1;}
		else 
			*p21=1;

return 0;
}
 



int razdelenie(char *mass1,int l){
int kl1=0;
int p11=1,p21=0;
int y=1;
int z=0;
char x1[255],a1[255],b1[255];
do{
 	kl1=0;
 	for(int n=0;n<l;n++){
    	if(p11==1 && mass1[n]!=' '  ){
   			strncat(a1,&mass1[n],1);
    }
    else if(p11==1 && a1[0]!=0 && mass1[n+1]!=' ' && mass1[n]==' '  ){
		p21=1;
  		p11=0;
  		continue;
   	 }
    else if(p21==1 && mass1[n]!=' '  ){
    	strncat(b1,&mass1[n],1);
    }
    else if(mass1[n]==' ' && mass1[n+1]!=' ' && p21==1){
   		p21=0;
    }
    if((p21==0 && p11==0)||(n==l-1)){
		if(n==l-1)
    	sort1(y,a1,b1,x1,&kl1,&p21,&p11,l);
  		else sort1( z,a1,b1,x1,&kl1,&p21,&p11,l);
    }}
	memcpy(mass1,x1,255);
	memset(x1,(char)0,sizeof(x1));
	}while(kl1!=0);

in_file(mass1);
return 0;
}

