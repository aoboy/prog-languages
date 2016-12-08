#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CountSetBits(int n)
{
	int count = 0;
	
	while(n) {
		n &= (n-1);
		++count;
	}
	return count;
}
/*----------------------------------------------------------------------------*/
void int2str(int x){
    if(x > 0){        
        int2str(x /10);
        printf("%c", (char)('0' + x%10));
    }else{                        
        printf("\0'\n");
    }
}
/*----------------------------------------------------------------------------*/
void divide(int n, int d){
  int q = 0;
  int r = 0;
  int dev = d; 
  
  while(1){
      //d = d << 1;
      q++;
      if(d < n){
        r = n - d;
      }else{
         break;
      }
      d = d << 1;
  } 
  printf("(%d, %d) = %d + %d\n", n, dev, q, r);
}
/*----------------------------------------------------------------------------*/
int myatoi(const char *string);

/*----------------------------------------------------------------------------*/
int myatoi(const char *string)
{
    int i;
    i=0;
    const char* ptr = string;
    while(*ptr)
    {
        i=(i<<3) + (i<<1) + (*ptr - '0');
        ptr++;

        // Dont increment i!

    }
    return(i);
}
/*----------------------------------------------------------------------------*/
int myatoi2(const char* string){
  int value = 0; 
  const char* ptr = string;
  if (ptr)
  {
    while (*ptr && (*ptr <= '9' && *ptr >= '0')) 
    {
      value = (value * 10) + (*ptr - '0');
      ptr++;
    }
  } 
  return value; 
} 
/*----------------------------------------------------------------------------*/
int my_strlen(char *s)
{
  char *p=s;

  while(*p!='\0')
    p++;

  return(p-s);
}
/*----------------------------------------------------------------------------*/
int my_strlen2(char *string)
{
  int length;
  char* ptr = string;
  
  for(length = 0; *ptr != '\0'; ptr++)
  {
    length++;
  }
  return(length);
}
/*----------------------------------------------------------------------------*/
void reverse_string(char* str){
    int i, j;
    i=j=0;

    j=strlen(str)-1;
    for (i=0; i<j; i++, j--)
    {
        str[i] ^= str[j] ;
        str[j] ^= str[i] ;
        str[i] ^= str[j] ;
    }
}
/*----------------------------------------------------------------------------*/
void reversestring(char* str, int len){
    int i, j;
    char temp;
    i=temp=0;
      
    j=len-1;
    for (i=0; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
/*----------------------------------------------------------------------------*/
int reverse(char* st, int i) {
  if (i<(strlen(st)/2)) {
    char c;
    c= st[i];
    st[i]=st[strlen(st)-i-1];
    st[strlen(st)-i-1]=c;
  }
  return reverse(st, i);
}
/*----------------------------------------------------------------------------*/
int reverse2(char *s){
    int i, c, ln = strlen(s);
    
    for (i = 0; i < ln/2; i++) {
        c = s[ln-1-i];
        s[ln-1-i] = s[i];
        s[i] = c;
    }
    return 0;
}
/*----------------------------------------------------------------------------*/
void reverseWords( char * str )
{
    int i = 0, j = 0;
    reversestring( str, strlen(str) ); // tsaf yrev si rac yM
    while( 1 ) // Loop forever
    {
        if( *(str+j) == ' ' || *(str+j) == '\0') // Found a word or reached the end of sentence
        {
            reversestring( str+i, j-i );
            i = j+1;
        }
        if( *(str+j) == '\0')
        {
            break;
        }
        j++;
    }
}
/*----------------------------------------------------------------------------*/
void strrev(char* str){
    reverseWords(str);
}
/*----------------------------------------------------------------------------*/
int main(int n, char** str)
{ 
    /*int a[] = {7,6,5,9,4,8,1,3,2,0}, i = 0;
  // Populate the array a
    for(i = 0; i < 10; i++){
        printf(" %2d", a[i]);
    }
    printf(" ->Sorted: ");
    quicksort(a, 0, 9);
    for(i = 0; i < 10; i++){
        printf(" %2d", a[i]);
    }
    printf("\n");
    
    int2str(atoi(str[1]));
    printf("\n");*/
    
    char gonga[]="antonio oliveira gonga\0";
    printf("before: %s\n", gonga);
    
    //strrev(gonga);
    //reverse_string(gonga);
    reverseWords(gonga);
    printf("after: %s\n", gonga);
    
    //divide(19, 4);
    
    printf("my atoi:%d, %d\n", myatoi("10"), myatoi2("150"));
    
    printf("num bits set in %d is %d\n", 15, CountSetBits(15));
    
    return 0;
}
