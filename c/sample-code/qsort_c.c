
#include <stdio.h>
#include <stdlib.h>

int count = 0;
void print_data(int *a, int n);
///=========================================================================/
///=========================================================================/
void quick_sort (int *a, int n) {
    int i, j, p, t;
    
    count++; 
    
    if (n < 2)
        return;
    
    //printf("Step: %2d: Pivot:%d :: ", count,a[n / 2]);
    //print_data(a,n);    
    
    p = a[n / 2];
    //p = a[n-1];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
	//swap here
        t    = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}
///=========================================================================/
///=========================================================================/
void merge (int *a, int n, int m) {
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    
    //copy ordered values into original array...
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    //printf("merging: ");
    //print_data(a,n);
    //free aux memory..
    free(x);
}
 
void merge_sort (int *a, int n) {
    count++;
    
    printf("Step: %2d: ", count);
    print_data(a,n);
    
    if (n < 2)
        return;
    //break array to sort into the middle
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}
static void mergeSort_srt(int *array, int lo, int n) {
        int low = lo;
        int high = n;
	
	count++;
	
	printf("Step: %2d: ", count);
	print_data(array,n);
		
        if (low >= high) {
            return;
        }
	
        int middle = (low + high) / 2;
        mergeSort_srt(array, low, middle);
        
        mergeSort_srt(array, middle + 1, high);
        
        int end_low = middle;
        
        int start_high = middle + 1;
        
        while ((lo <= end_low) && (start_high <= high)) {
            if (array[low] < array[start_high]) {
                low++;
            } else {
                int Temp = array[start_high];
		int k;
                for (k = start_high - 1; k >= low; k--) {
                    array[k + 1] = array[k];
                }
                array[low] = Temp;
                low++;
                end_low++;
                start_high++;
            }
        }
    }
///=========================================================================/
///=========================================================================/
void generate_data(int* a, int n){
  int i;
  
  printf("Before: ");
  for(i = 0; i < n; i++){
      a[i] = random()%100;
      printf("%2d%s", a[i], i== (n-1)? "\n" : " ");
  }
}
///=========================================================================/
///=========================================================================/
void print_data(int *a, int n){
  int i;
  for(i = 0; i < n; i++){
      //a[i] = rand()%100;
      printf("%2d%s", a[i], i== (n-1)? "\n" : " ");
  }  
}

///=========================================================================/
///=========================================================================/
int main(){
  int a[20];
  int n;
  
    n = sizeof(a)/sizeof(a[0]);
    
    srandom(77171);
    
    generate_data(a, n);

    count = 0;
    quick_sort(a,n);
    
    printf("After: ");
    print_data(a,n);   
    printf("Cost: %d\n", count);
    
    //srandom(77173);
    generate_data(a, n);

    count = 0;
    //merge_sort(a,n);
    mergeSort_srt(a, 0,n-1);

    printf("After: ");
    print_data(a,n);   
    printf("Cost: %d\n", count);
        
    return 0;
}