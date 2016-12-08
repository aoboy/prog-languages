#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int a; 
    unsigned short int x;
}T;

typedef union{
    int x;
    unsigned short a;
}A;

struct list{
  struct list *next;
  int val;
};

#define HELLO_WORLD  printf("Hello World...!\n")
/*this allows to print numbers from 1 to 100
  without using a loop
       int count = 1;
       LABEL: printf("seqno: %3d\n", count);
       count++;
       if(count < 101) goto LABEL;
*/
/*
 printf("The number: %2d is %s a of 2\n", n, ((n!=0)&& ((n&(n-1))==0)) ? "power": "not power");
*/
/*multiply a number by seven without using * operator
  p = (n << 3) - n;
      printf("%d multiplied by 7 is %d\n", n, p);
*/
/*swap two numbers withou using a third variable.
 printf("a=%d, b=%d -> ", a, b );
      a = a+b;
      b = a-b;
      a = a-b;

      printf("after a=%d, b=%d\n", a, b );
*/
/*----------------------------------------------------------------------------*/
int mystr_cmp(char *s1, char *s2){
    char *p1 = s1, *p2 = s2;
    while(*p1 == *p2){
        if(*p1 == '\0'){ 
            return 0;
        }else{
            *p1++;
            *p2++;
        }        
    }
    return (*p1 - *p2);
}
/*----------------------------------------------------------------------------*/
void powerof2(int n){
    printf("The number: %2d is %s a of 2\n", n, ((n!=0)&& ((n&(n-1))==0)) ? "power": "not power");
}
/*----------------------------------------------------------------------------*/
int f(int a){
   return a^3; 
}
/*----------------------------------------------------------------------------*/
void integer2bin(unsigned int n){
    if(n == 0){
        printf("\n");
        return;
    }else{        
        integer2bin(n/2);        
        printf("%d", n%2);
    }    
}
/*----------------------------------------------------------------------------*/
void integer2bin2(int num)
{
  int temp;
  if(num)
  {
    temp = num % 2;
    integer2bin2(num >>= 1);
    printf("%d",temp); 
  }
}
/*----------------------------------------------------------------------------*/
int pow_1(int x, int y){
  if(y == 1) return x ;
  return x * pow_1(x, y-1) ;
}
/*----------------------------------------------------------------------------*/
int pow_2(int x, int n)
{
  if(n==0)return(1);
  else if(n%2==0)
  {
    return(pow_2(x,n/2)*pow_2(x,(n/2)));
  }
  else 
  {
    return(x*pow_2(x,n/2)*pow_2(x,(n/2)));
  }
}
/*----------------------------------------------------------------------------*/
struct list *new(int val){
    struct list *node = (struct list*)malloc(sizeof(struct list));
    if(node != NULL){
        node->val = val;
        node->next = NULL;
        return node;
    }
    return NULL;    
}
/*----------------------------------------------------------------------------*/
void insert(struct list **node, int val){
    if(*node == NULL){
        *node = new(val);
    }else{
        insert(&(*node)->next, val);
    }
}
/*----------------------------------------------------------------------------*/
void print_list(struct list *node){
    if(node != NULL){
        printf(" %2d ", node->val);
        print_list(node->next);
    }
}
/*----------------------------------------------------------------------------*/
void print_reverse(struct list *node){
    if(node != NULL){
        print_reverse(node->next);
        printf(" %2d ", node->val);
    }
}
/*----------------------------------------------------------------------------*/
void free_list(struct list *node){
    if(node != NULL){
        free_list(node->next);
        free(node);
    }
}
/*----------------------------------------------------------------------------*/
struct list *reverseRec(struct list *node, struct list *prev){
    if(node->next == NULL){
        node->next = prev;
        return node;
    }else{
        struct list *tmp = reverseRec(node->next, node);
        node->next = prev;
        return tmp;
    }
}
/*----------------------------------------------------------------------------*/
struct list * reverse(struct list * ptr ){
    struct list * temp;
    struct list * previous = NULL;
    while(ptr != NULL) {
        temp = ptr->next;
        ptr->next = previous;
        previous = ptr;
        ptr = temp;
    }
    return previous;
}
/*----------------------------------------------------------------------------*/
struct list * reverseRec2(struct list * head, struct list * acc) {
    if(head == NULL) {
        return acc;
    } else {
        struct list * tmp = head->next;
        head->next = acc;
        return reverseRec2(tmp, head);
    }
}
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv){
	/*if(HELLO_WORLD){
        }*/
      int n = atoi(argv[1]), p;
      int m = atoi(argv[2]);
      
      printf("pow(%d, %d)=%d\n", n, m, pow_2(n, m));      
      
      integer2bin(n);
      printf("\n");
     
    
      struct list *head = NULL, *revhead;
      insert(&head, 2);
      insert(&head, 1);
      insert(&head, 5);
      insert(&head, 0);
      printf("before\n");
      print_list(head);
      printf("before\n");
      print_reverse(head);
      //revhead = reverseRec2(head, NULL);
      revhead = reverse(head);
      printf("after\n");
      print_list(revhead);
      printf("free\n");
      free_list(revhead);
      printf("\n");
      
                                 
 return 0;
}
