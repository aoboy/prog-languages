#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define HASH_SIZE 8


struct list{
    struct list *next;
    int value;
};

typedef struct{
    struct list *list;
}hash_t;
/*----------------------------------------------------------------------------*/
struct list *newNode(int val){
    struct list *node = (struct list *)(malloc)(sizeof(struct list));
    if(node != NULL){
        printf("%2d ", val);
        node->value = val;
        node->next = NULL;
        return node;
    }
    return NULL;
}
/*----------------------------------------------------------------------------*/
void hash_insert(struct list **head, int val){    
    
    if(*head == NULL){
        *head = newNode(val);
    }else{
        hash_insert(&(*head)->next, val);
    }
}
/*----------------------------------------------------------------------------*/
void hash_remove(struct list **node, int val){
    if(*node == NULL){
        return;
    }else{
        if((*node)->value == val){
          struct list *p = *node;
          *node = (*node)->next;
          printf("removing %d\n", p->value);
          free(p);
        }else{
            hash_remove(&(*node)->next, val);
        }
    }
}
/*----------------------------------------------------------------------------*/
void hash_free(struct list *node){
    if(node != NULL){
        printf("%2d ", node->value);
        hash_free(node->next);
        free(node);
    }
}
/*----------------------------------------------------------------------------*/
void hash_print(struct list *node){
    if(node != NULL){
        printf("%2d ", node->value);
        hash_print(node->next);
    }
}
/*----------------------------------------------------------------------------*/
int has_substring(const char* str, const char* find){
   int i,j, not_found = 0;
    if(str[0] == '\0' && find[0] == '\0'){
	return TRUE;
    }
    for(i = 0; str[i] !='\0'; i++){
         not_found = 0;
         for(j = 0; find[j] !='\0'; j++){
	    if(str[i+j] != find[j]){
		not_found = TRUE;
		break;
            }
         }
         if(not_found == FALSE){
           printf("'%s'.contains('%s')\n", str, find);
           return i;
         }

    }
  return -1;
}

int main(int a, char** b){
int i, k, num_size;

const char *name="Antonio Gonga";
const char *sub_str = "io";

printf("'%s' contains '%s' @ %d\n", name, sub_str, has_substring(name, sub_str));


//hash_t hash[HASH_SIZE];
/*hash_t *hash=NULL;

hash = malloc(HASH_SIZE*sizeof(hash_t));
if(!hash){
    printf("malloc faild\n");
    return -1;
}

printf("enter number elements: ");
scanf("%d", &num_size);

for(i = 0; i < HASH_SIZE; i++){
    hash[i].list = NULL;
}*/

/*printf("inserting: \n");
for(i = 0; i < num_size; i++){
    int val = random()%200;
    printf("enter value[%d]: ", val);   
    //scanf("%d", &val);
    int key = val%HASH_SIZE;

    //printf("%d", i);
    hash_insert(&hash[key].list, val);
}*/


/*printf("\nprinting:\n");
for(i = 0; i < HASH_SIZE; i++){
    if(hash[i].list)
        printf("HASH[%d] = [", i);
    
    hash_print(hash[i].list);    
    
    if(hash[i].list)
        printf("]\n");
}*/
//hash_remove(&hash[val/10].list, val);

/*printf("\nprinting:\n");
for(i = 0; i < HASH_SIZE; i++){
    printf("\nHASH[%d] = [", i);
    hash_print(hash[i].list);    
    printf("]\n");
}*/

/*printf("\nfreeing hash:\n");
for(i = 0; i < HASH_SIZE; i++){
    hash_free(hash[i].list);
    printf("\n");
}*/

return 0;
}
