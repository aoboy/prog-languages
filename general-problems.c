#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*============================================================================*/
int  has_substring(char *p, char *t){
  int i,j;
  int m, n; //length of strings
    
  m = strlen(p);
  n = strlen(t);

  for(i = 0; i <= (n-m); i++){
	j = 0;
	while((j< m) && (t[i+j] == p[j])){
		j++;
	}
	if(j == m) {
	   return i;
	}
  }
  
  return -1;
}
/*============================================================================*/
long int power(long int a, long int n){
    if(n == 0){
        return 1;
    }else{
         long int x = power(a, n/2);
         if(n %2 == 0){
            return x*x;
         }else{
            return a*x*x;
         }
    }
}
/*============================================================================*/
/*============================================================================*/
int main(){
 int i= 0;
 char *a ="abba", *b="aababba";
  i =  has_substring(a,b);
  if(i != -1)
     printf("%s-%s ->b[%d]=%s\n",a,b,i, &b[i]);

  long int x = 2, n =7;
  
  printf("%li^%li=%li\n", x,n, power(x,n));
  
return 0;
}
