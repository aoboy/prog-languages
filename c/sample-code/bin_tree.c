/* binary search tree */

#include <stdio.h>
#include <stdlib.h>

typedef int T;                  /* type of item to be stored */
#define compLT(a,b) ((a) < (b))
#define compGT(a,b) ((a) > (b))
#define compEQ(a,b) (a == b)


struct list{
    struct list *next;
    int data;
};

struct list *rootList = NULL;
void list_insert(struct list **node, int data);

typedef struct Node_ {
    struct Node_ *left;         /* left child */
    struct Node_ *right;        /* right child */
    struct Node_ *parent;       /* parent */
    T data;                     /* data stored in node */
} Node;

Node *root = NULL;               /* root of binary tree */

Node *insertNode(T data) {
    Node *x, *current, *parent;

   /***********************************************
    *  allocate node for data and insert in tree  *
    ***********************************************/

    /* find x's parent */
    current = root;
    parent = 0;
    while (current) {
        if (compEQ(data, current->data)) return (current);
        parent = current;
        current = compLT(data, current->data) ? 
            current->left : current->right;
    }

    /* setup new node */
    if ((x = malloc (sizeof(*x))) == 0) {
        fprintf (stderr, "insufficient memory (insertNode)\n");
        exit(1);
    }
    x->data = data;
    x->parent = parent;
    x->left = NULL;
    x->right = NULL;

    /* insert x in tree */
    if(parent)
        if(compLT(x->data, parent->data))
            parent->left = x;
        else
            parent->right = x;
    else
        root = x;

    return(x);
}

void deleteNode(Node *z) {
    Node *x, *y;

   /*****************************
    *  delete node z from tree  *
    *****************************/

    /* y will be removed from the parent chain */
    if (!z || z == NULL) return;

    /* find tree successor */
    if (z->left == NULL || z->right == NULL)
        y = z;
    else {
        y = z->right;
        while (y->left != NULL) y = y->left;
    }

    /* x is y's only child */
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    /* remove y from the parent chain */
    if (x){
        x->parent = y->parent;
    }
    
    if (y->parent){
        if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
    }else{
        root = x;
    }
    /* y is the node we're removing */
    /* z is the data we're removing */
    /* if z and y are not the same, replace z with y. */
    if (y != z) {
        y->left = z->left;
        if (y->left) 
            y->left->parent = y;
        
        y->right = z->right;
        
        if (y->right) 
            y->right->parent = y;
        
        y->parent = z->parent;
        
        if (z->parent){
            if (z == z->parent->left){
                z->parent->left = y;
            }else{
                z->parent->right = y;
            }
        }else{
            root = y;
        }
        free (z);
    } else {
        free (y);
    }
}
/*----------------------------------------------------------------------------*/
Node *findNode(T data) {

   /*******************************
    *  find node containing data  *
    *******************************/

    Node *current = root;
    while(current != NULL)
        if(compEQ(data, current->data)){
            //printf("found %d \n", data);
            return (current);
        }else{
            current = compLT(data, current->data) ? 
                current->left : current->right;
        }
    return(0);
}
/*----------------------------------------------------------------------------*/
void inorder_tree(Node *node){
    if(node != NULL){     
        
        inorder_tree(node->left);       
        printf(" %d", node->data);
        list_insert(&rootList, node->data);
        inorder_tree(node->right);
    }    
}
/*----------------------------------------------------------------------------*/
void inv_tree(Node *node){
    if(node != NULL){     
        inorder_tree(node->right);
        printf(" %2d ", node->data);
        inorder_tree(node->left);                                               
    }    
}
/*----------------------------------------------------------------------------*/
void preorder_tree(Node *node){
    if(node != NULL){     
        printf(" %d", node->data);
        preorder_tree(node->left);               
        preorder_tree(node->right);
    }    
}
/*----------------------------------------------------------------------------*/
void postorder_tree(Node *node){
    if(node != NULL){             
        postorder_tree(node->left);               
        postorder_tree(node->right);
        printf(" %d", node->data);
    }    
}
/*----------------------------------------------------------------------------*/
struct list *newNode(int data){
    struct list *node = malloc(sizeof(struct list));
    if(node == NULL) return NULL;
    
    node->data = data;
    node->next = NULL;
    return node;
}
/*----------------------------------------------------------------------------*/
void list_insert(struct list **node, int data){
    if(*node == NULL){
        *node = newNode(data);
    }else{
        return list_insert(&(*node)->next, data);
    }
}
/*----------------------------------------------------------------------------*/
struct list* list_invert(struct list *node){
    struct list *prev = NULL, *tmp;
    if(node == NULL){
        return prev;
    }else{
        while(node != NULL){
            tmp = node->next;
            node->next = prev;
            prev = node;
            node = tmp;
        }
        return prev;
    }
}
/*----------------------------------------------------------------------------*/
void list_print(struct list *node){
    while(node != NULL){
        printf("%2d ", node->data);
        node = node->next;
    }
}
/*----------------------------------------------------------------------------*/
void list_free(struct list *node){
    struct list *p = node;
    while (node != NULL){
       p = node->next;
       free(node);
       node = p;
    }
}
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv) {
    int i, maxnum, random;
    
    /* command-line:
     *
     *   bin maxnum random
     *
     *   bin 5000        // 5000 sequential
     *   bin 2000 r      // 2000 random
     *
     */
    int a[] = {20, 7, 4, 16, 38, 37, 43};
    maxnum = 7; //atoi(argv[1]);
    //random = argc > 2;

    /*if ((a = malloc(maxnum * sizeof(*a))) == 0) {
        fprintf (stderr, "insufficient memory (a)\n");
        exit(1);
    }*/

    //if (random) { /* random */
        /* fill "a" with unique random numbers */
        //for (i = 0; i < maxnum; i++) a[i] = rand();
        //printf ("ran bt, %d items\n", maxnum);
    //} else {
        //for (i=0; i<maxnum; i++) a[i] = i;
        //printf ("seq bt, %d items\n", maxnum);
    //}


    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }

    for (i = maxnum-1; i >= 0; i--) {
        findNode(a[i]);
    }

    /*for (i = maxnum-1; i >= 0; i--) {
        deleteNode(findNode(a[i]));
    }*/
    printf("InOrder: ");
    inorder_tree(root);
    printf("\nPostOrder: ");
    postorder_tree(root);
    printf("\nPreOrder: ");
    preorder_tree(root);
    printf("\nlist: ");
    list_print(rootList);
    list_free(rootList);
    printf("\nInvList: ");
    inv_tree(root);
    //rootList = list_invert(rootList);     
    //list_print(rootList);
    //list_free(rootList);
    /*deleteNode(findNode(20));  
    print_tree(root);
    printf("\n");
    print_tree2(root);
    printf("\n");
    print_tree3(root);*/
    printf("\n");
    for (i = maxnum-1; i >= 0; i--) {
        deleteNode(findNode(a[i]));
    }
    return 0;
}

