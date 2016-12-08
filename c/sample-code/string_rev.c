#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void swap_char(char* str){
 int i, len = strlen(str);
 int j = len-1; 
 char c=0;
 for(i = 0; i < (len)/2; i++, j--){
     c = str[j];
     str[j] = str[i];
     str[i] = c;
 }
}

main()
{
  char gonga[]="antonio oliveira gonga";
  printf("before: %s\n", gonga);
  swap_char(gonga);
  printf("after: %s\n", gonga);
// getch();
}
