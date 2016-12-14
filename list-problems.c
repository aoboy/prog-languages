#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*============================================================================*/
struct node{
  int data;
  struct node *next;
};
/*============================================================================*/
struct node *new_node(int data){
    struct node *nnode;
    
    nnode = (struct node*)malloc(sizeof(struct node));
    
    assert(nnode != NULL);
    
    nnode->data   = data;
    nnode->next   = NULL;
    
    return nnode;
}
/*============================================================================*/
void push(struct node **head, int data){
    struct node *newnode;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    
    assert(newnode != NULL);
    
    newnode->data = data;
    newnode->next = (*head);
    (*head)   = newnode;
}
/*============================================================================*/
int pop(struct node **head){
  int data; 
  struct node *ref;
  
  ref = *head;
  assert(head != NULL);
  
  data =  ref->data;
  *head = ref->next;

  free(ref);
  
  return data;
}
/*============================================================================*/
int length(struct node *l){
    int i=0;
    struct node *h = l;
    while(h != NULL){
        i++;
        h = h->next;
    }
    return i;
}
/*============================================================================*/
void insert_nth(struct node **head, int index, int data){
    struct node *ref;
    
    int i = 0;
    
    if(index == 0){
        push(head, data);
        return;
    }
    
    ref = *head;
    while(ref != NULL){
        if(i == (index-1)){
              
              push(&ref, data);
              
              return;
        }
        i++;
        ref = ref->next;
    }        
}
/*============================================================================*/
void sorted_insert(struct node **head, struct node* new_data){
    struct node **hptr;
    
    hptr = head;
    
    while( (*hptr != NULL) && ((*hptr)->data < new_data->data)){
        
        hptr = &((*hptr)->next);
    }
    
    new_data->next = *hptr;
    
    *hptr          = new_data;
}
/*============================================================================*/
void insert_sort(struct node **head){
        struct node *new_list = NULL;
        
        struct node *nodeL = *head;
        struct node *holdL;
        
        while(nodeL != NULL){
            holdL  = nodeL->next;
            sorted_insert(&new_list, nodeL);
            
            nodeL = holdL;
        }
        *head = new_list;
}
/*============================================================================*/
void append(struct node **head, struct node **new_data){
    
    if(*head == NULL){
        *head = *new_data;
    }else{
        
        struct node *ref = *head;
        
        while(ref->next != NULL){
            ref = ref->next;
        }
        ref->next = *new_data;        
    }
    new_data = NULL;
}
/*============================================================================*/
//if list is not sorted, call sorting first...
void remove_duplicates(struct node **head){
    struct node *hptr = *head;
    
    if(hptr == NULL) {
        return;
    }else{
       while(hptr->next != NULL){
            if(hptr->data == hptr->next->data){
                struct node *holdL = hptr->next->next;
                free(hptr->next);
                
                hptr->next = holdL;
            }else{
                hptr = hptr->next;
            }
       } //end while           
    } //end else..    
}
/*============================================================================*/
void move(struct node **src_ptr, struct node **dst_ptr){
    struct node *src_ref = *src_ptr;
    
    assert(src_ref != NULL);
    
    *src_ptr   = src_ref->next;
    
    src_ref->next = *dst_ptr;
    *dst_ptr       = src_ref;
}
/*============================================================================*/
void reverse_l(struct node **head){
    struct node * res   = NULL;
    struct node * hptr  = *head;
    struct node * holdL;
    
    while(hptr != NULL){
        holdL = hptr->next; //hold remaining list..
        hptr->next = res;   //set next pointer to res
        res        = hptr;  //set res pointer to point to hptr
        
        hptr       = holdL; //restore pointer
    }
    *head = res;  //now point the head ptr to the new list..
}
/*============================================================================*/
struct node *middle_l(struct node *head){
    struct node *fast, *slow;
    
    if(head == NULL || (head->next == NULL)){
        return head;
    }
    fast = head;
    slow = head;
    
    while((fast->next != NULL) && (fast->next->next != NULL)){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;    
}
/*============================================================================*/
/* h1=[1,3,5,7,9] h2=[2,4,6,8] 
 * h3=[1]; h3->next = merge([3,5,7,9], [2,4,6,8])
 * h3=[1,2]; h3->next = merge([3,5,7,9], [4,6,8])
 */
struct node *merge(struct node *h1, struct node *h2){
    struct node *h3;
    if(h1 == NULL) {return h2;}
    if(h2 == NULL) {return h1;}
    
    if(h1->data < h2->data){
        h3 = h1;
        h3->next = merge(h1->next, h2);
    }else{
        h3 = h2;
        h3->next = merge(h1, h2->next);
    }
    
    return h3;
}
/*============================================================================*/
struct node *merge_2(struct node *h1, struct node *h2){
    struct node *h3;
    //dummy pointer
    struct node *hp = (struct node*)malloc(sizeof(struct node));
    
    hp->next = NULL; 
    
    h3 = hp;
    while((h1 != NULL) && (h2 != NULL)){
        if(h1->data < h2->data){
            h3->next = h1;
            h1 = h1->next;
        }else{
            h3->next = h2;
            h2 = h2->next;
        }
        h3 = h3->next;
    }
    
    //add the remaining of h1 or h2 in case both list have different sizes
    if(h1 == NULL){
        h3->next = h2;
    }else{
        h3->next = h1;
    }
    
    //free the dummy pointer
    struct node *tmp = hp->next;
    free(hp);
    
    return tmp;
}
/*============================================================================*/
struct node* merge_sort(struct node *h){
    if((h == NULL) || (h->next == NULL)){
        return h;
    }
    //split list into two
    struct node *l1 = middle_l(h);
    struct node *l2 = l1->next;
    
    //divide/split the lists
    l1->next = NULL;
    
    return merge_2(merge_sort(h), merge_sort(l2));
}
/*============================================================================*/
void quick_sort(int *a, int n){
    int i,j,p,tmp;
    
    if(n < 2){
        return;        
    }
    
    p = a[n/2]; //pivot p = a[n-1];
    
    for(i = 0, j = n-1; ; i++, j--){
        while(a[i] < p) {
            i++;            
        }
        while(p < a[j]){
            j--;
        }
        
        if(i >= j){
            break;
        }
        tmp  = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    quick_sort(a, i);
    quick_sort(a+i, n-i);    
}
/*============================================================================*/
void print_list(struct node *l){
    struct node *h = l;
    
    for(; h != NULL; h = h->next){
        printf("%2d %s", h->data, (h->next == NULL)? "\n":"");
    }
}
/*============================================================================*/
void free_list(struct node *l){
    struct node *tmp=NULL;
    for(; l!= NULL; l = tmp){
        tmp = l->next;
        free(l);
    }
}
/*============================================================================*/
int main()
{
  /* Start with the empty list */
  //struct node* res = NULL;
  struct node* a = NULL;
  
  /*create an unsorted linked lists */
  push(&a, 17);
  push(&a, 1);
  push(&a, 15); 
  push(&a, 12);
  push(&a, 3);
  push(&a, 2); 
  push(&a, 2); 
  push(&a, 3); 
  
  printf("\n Linked List is: ");
  print_list(a);    
  
  /* Sort the above created Linked List */
  //a=merge_sort(a);
  
  insert_sort(&a);
  
  printf("\nSorted Linked List is: ");
  print_list(a);     
  
  //remove duplicates
  remove_duplicates(&a);
  printf("After removing duplicates: ");
  print_list(a);  
  
  reverse_l(&a);
  printf("after reversing: ");
  print_list(a);  
  
  //free list
  free_list(a);  
  getchar();
  //print_list(a);  
  
  return 0;
}
