#include <stdio.h>
#include <stdlib.h>

void division(int p, int d){
int r = 0, q = 0;
int n = p;   
    if(p < d){
       printf("%d/%d = 0\n", p, d);
    }else{
       while(p >= d){
	 p = p - d;
         q++;
         r = p;
       }
       printf("%d/%d = %d + %d\n", n, d, q, r);       
    }
}
main(int a, char** b){

int p = atoi(b[1]);
int d = atoi(b[2]);

division(p,d);
}
