#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"
int l=0;
char mass[255],x[255],a[255],b[255];
bool p1=true,p2=false;
int kl=0;
void sort(bool var)
{
if((unsigned char)a[0]>(unsigned char)b[0]){
 strcat(x,b);
 strcat(x," ");
 kl++;
 if(var)
    strcat(x,a);
}
else{
 strcat(x,a);
 strcat(x," ");
 if(var)
    strcat(x,b);
 else
    memcpy(a,b,255);
}
if(var)
 memset(a,(char)0,sizeof(a));
memset(b,(char)0,sizeof(b));
if(var)
{p2=false;
 p1=true;
}
else p2=true;
}
 
void file()
{ FILE *text;
int n;
text=fopen("text.txt","r");
fgets(mass,10000, text);
l=strlen(mass);
do{
 kl=0;
 for( n=0;n<l;n++){
    if(p1&&mass[n]!=' '  ){
   strncat(a,&mass[n],1);
    }
    else if(p1&&a[0]!=0&&mass[n+1]!=' ' && mass[n]==' '  ){
	p2=true;
   p1=false;
   continue;
    }
    else if(p2&&mass[n]!=' '  ){
   strncat(b,&mass[n],1);
    }
    else if(mass[n]==' ' && mass[n+1]!=' ' && p2){
   p2=false;
    }
    if((!p2 && !p1)||(n==l-1)){
   if(n==l-1)
    sort(1);
   else sort(0);
    }}
 memcpy(mass,x,255);
 memset(x,(char)0,sizeof(x));
}while(kl!=0);

fclose(text);
FILE* itog;
itog=fopen("itog.txt","w");
fwrite(&mass,sizeof(mass),1,itog);
fclose(itog);


printf("Result:\n%s",mass);



}
