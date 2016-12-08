#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------*/
int bin_search(long int *a, int n_o, int n_n, int val){
int m, cost = 0;
    while(1){
	cost++;
	m = (n_o + n_n)/2;
        if(val < a[m]){
	   n_n = m - 1;
        }else if(val > a[m]){
	   n_o = m + 1;
	}else{
          printf("found .. a[%d] = %d cost: %2d\n", m, val, cost);
	  return a[m];
	}
	if(n_o > n_n){
		printf("not found..!\n");
		return -1;
	}
    }
}
/*----------------------------------------------------------------------------*/
int main(int argc, char** argv){
long int m = atoi(argv[1]), n=atoi(argv[2]);
long int i, a[n];

 //int n = sizeof(a)/sizeof(a[0]);
 
 printf("binary search:");
 for(i = 0; i < n; i++){
    a[i] = i+1;
    printf("%2ld%s", a[i], i==n-1?"\n":" ");
 }

 bin_search(a, 0, n, m);

 return 0;
}
