#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x) > (y)? (x) : (y))

struct btree{
    int data;
    struct btree *left;
    struct btree *right;
};
/*----------------------------------------------------------------------------*/
//struct btree *root = NULL;
/*----------------------------------------------------------------------------*/
struct btree* newNode(int data){
    struct btree *node = (struct btree*)malloc(sizeof(struct btree));
    if(node == NULL)
      return NULL;
    
    node->data = data;
    node->left = NULL;
    node->right= NULL;
    return node;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void insert(struct btree **node, int data){
    
    if(*node == NULL){  
          printf("<-%d ", data);
         *node = newNode(data);
    }else{        
            if(data < (*node)->data){                
                insert(&(*node)->left, data);
            }else if(data > (*node)->data){
                //printf(" ->%d ", data);
                insert(&(*node)->right, data);
            }                        
    }
}
/*----------------------------------------------------------------------------*/
void remove_node(struct btree *node, int data){
    struct btree *parent, *tmp;
    parent = tmp = node;

}
/*----------------------------------------------------------------------------*/
void print_tree(struct btree *node){
    if(node != NULL){     
        
        print_tree(node->left);       
        printf(" %d", node->data);
        print_tree(node->right);
    }    
}
/*----------------------------------------------------------------------------*/
void print_tree2(struct btree *node){
    if(node != NULL){     
        printf(" %d", node->data);
        print_tree2(node->left);               
        print_tree(node->right);
    }    
}
/*----------------------------------------------------------------------------*/
void print_tree3(struct btree *node){
    if(node != NULL){             
        print_tree3(node->left);               
        print_tree3(node->right);
        printf(" %d", node->data);
    }    
}
/*----------------------------------------------------------------------------*/
void free_btree(struct btree *node){
    if(node != NULL){
        //printf("rm %d ", node->data);
        free_btree(node->left);
        free_btree(node->right);
	printf("rm %d ", node->data);
        free(node);
    }
}
/*----------------------------------------------------------------------------*/
int height(struct btree * node){
    if(node == NULL){
        return -1;
    }else{
        return (1 + max(height(node->left), height(node->right)));
    }
}
/*----------------------------------------------------------------------------*/
int length(struct btree *node){
    if(node == NULL){
        return 0;
    }else{
        return (1 + length(node->left) + length(node->right));
    }
}
/*----------------------------------------------------------------------------*/
void find_tree(struct btree *node, int data){
    if(node == NULL){
        printf(" %d not found\n", data);
        return;
    }else{
        if(node->data < data){
           find_tree(node->right, data);
        }else if(node->data > data){
            find_tree(node->left, data);
        }else{
            printf("found:(%d, %d)\n", node->data, data);
        }
    }
}
/*----------------------------------------------------------------------------*/
int main(){
    printf("inserting 5, 2,10\n");
    //struct btree *root = NULL;
    struct btree *root = NULL;
    
    
    insert(&root, 20);
    insert(&root, 7); 
    insert(&root, 4);
    insert(&root, 16);    
    insert(&root, 38); 
    insert(&root, 37);
    insert(&root, 43);
    insert(&root, 15);
    insert(&root, 46);
    insert(&root, 56);
    insert(&root, 48);
   
    printf("\n");
    print_tree(root);
    printf("\n");
    print_tree2(root);
    printf("\n");
    print_tree3(root);
    printf("\n");
    find_tree(root, 31);
    printf("height: %d \t", height(root));
    printf("length: %d\n", length(root));
    printf("freeing: ");
    free_btree(root);
    printf("\n");
    return 1;
}
