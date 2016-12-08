#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[]={7, 4, 10, 8, 2, 9, 1, 3, 6, 5};
int arr1[10];

void insert_sort(int *a, int ao, int an){
}
/*----------------------------------------------------------------------------*/
int partition(int arr[], int left, int right){
      int tmp, i = left, j = right;
   
      int pivot = arr[(left + right) / 2];
     
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
     
      return i;
}
/*----------------------------------------------------------------------------*/
void quick_sort2(int arr[], int left, int right) {
      int index = partition(arr, left, right);
      if (left < index - 1)
            quick_sort2(arr, left, index -1);
      if (index < right)
            quick_sort2(arr, index, right);
}
/*----------------------------------------------------------------------------*/
void quick_sort(int arr[], int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      int k;
      printf("\npivot:%d\n", pivot);
      for(k = 0; k < 10; k++){
        printf("%2d ", arr[k]);
      }
      /* recursion */
      if (left < j)
            quick_sort(arr, left, j);
      if (i < right)
            quick_sort(arr, i, right);
}
/*----------------------------------------------------------------------------*/
void shell_sort2(int *a, int N){
  int i, j, k, mid = 0, tmp = 0;
  
  for(i = 0; i < N; i++){      
      for(j = i+2; j > 0; j--){          
          if((a[j-1] >  a[j])){
              tmp    = a[i];
              a[i]   = a[j];
              a[j] = tmp;  
              //printf("\nswap(%d <-> %d)", a[i], a[j]);
              //break;
          }/*else{
            break;
          }*/
      }
      //printf("\nswap(%d <-> %d)", a[i], a[j]);
      printf("\n");
      for(k = 0; k < N; k++){
           printf("%2d ", a[k]);
      }
  }
  printf("n_ops: %d\n", mid);
}
/*----------------------------------------------------------------------------*/
void shell_sort(int *a, int N){
  int i, j, k, mid = 0, tmp = 0, h=1;
  
  while(h < (N-1)) h = h*3 +1;
  printf("H: %d\n", h);
  h = h/3; //h /=3;
  
  for(;  h > 0; h /= 3){
      for(i = 0 + h; i < N; i++){
          tmp = a[i];
          int op = 0;
          for(j = i-h ; j >= 0 && (a[j] >  tmp); j = j - h){
             a[j+h]   = a[j];
             op = 1;
             mid++;
          }        
          a[j+h] = tmp;
          //printf("\nswap(%d <-> %d)", a[i], tmp);
          if(op){
              printf("\n");
              for(k = 0; k < N; k++){
                  printf("%2d ", a[k]);
              }
          }
      }     
  }
  printf("n_ops: %d\n", mid);
}
/*----------------------------------------------------------------------------*/
void merge(int *a, int lo, int mid, int n) {

int low = lo, high = n;
      
      if(low >= high){
            return;
      }       
      //int end_low = middle;
      int end_low = mid;
      
      int start_high = mid + 1;
      
      while ((lo <= end_low) && (start_high <= high)) {
          if (a[low] < a[start_high]) {
              low++;
          } else {
              int Temp = a[start_high];
              int k;
              for (k = start_high - 1; k >= low; k--) {
                  a[k + 1] = a[k];
              }
              a[low] = Temp;
              low++;
              end_low++;
              start_high++;
          }
      }
}
/*----------------------------------------------------------------------------*/
void merge_sort(int *a, int left, int right){
   
    if(left < right){
        int mid = (left +  right)/2;
      
        merge_sort(a, left, mid);
      
        merge_sort(a, mid + 1, right);
                
        merge(a, left, mid, right);              
    }    
}
/*----------------------------------------------------------------------------*/
void bubble_sort(int *a, int lo, int len){
    int i, swapped = 1;
    while(swapped){
        swapped = 0;
        for(i = len; i > 0 ; i--){            
            if(a[i-1] > a[i]){
                int tmp = a[i-1];
                a[i-1]  = a[i];
                a[i]    = tmp;
                swapped = 1;
            }
        }        
    }    
}
/*----------------------------------------------------------------------------*/
int main(){
int copy[20];
int i, a[]={7, 4, 10, 8, 2, 9, 1, 3, 6, 5};
int b[] = {'g', 'z', 'a', 'j', 'd', 'e', 'v', 't', 'm', 'o'}; 
int c[] = {3, 5, 1, 2, 4};
char* d = "shksiejuqo";
//int c[10];

  printf("before: \n");
  for(i = 0; i < 10; i++){
  //for(i = 0; i < 5; i++){
      //printf("%d ", c[i]);
      printf("%d ", a[i]);
  }
   
   printf("\n--------------------------------------\n");
   //shell_sort(c, 5);
   shell_sort(a, 10);
   //quick_sort2(a, 0, 9);
   //merge_sort(b, 0, 9);
   //bubble_sort(a, 0, 9);
   //mergeSort_srt(a, 0, 9);
   printf("after:\n");
   for(i = 0; i < 10; i++){
   //for(i = 0; i < 5; i++){
       //printf("%d ", c[i]);
       printf("%d ", a[i]);
   }
   printf("\n");
   return 0;
}
