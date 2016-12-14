/***
 * This code is based on two books:
 * 	1. Steven S. Skiena 'The Algorithm Design Manual'
 * 	2. Thomas Cormen, Charles Leiserson, Ronald Rivest Clifford Stein
 * 		'Introduction to Algorithms'
 * 
 * @author: António Gonga::::gonga@kth.se 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef enum{
    TREE_MIN,
    TREE_MAX
}options_t;
/*============================================================================*/
typedef int item_t;

typedef struct tree{
    item_t key;
    struct tree *parent;
    struct tree *left;
    struct tree *right;
}tree_t;

typedef struct{
  tree_t *root;
}bst_t;
/*============================================================================*/
tree_t *tree_create_node(item_t key){
   tree_t *node;
   
   node = (tree_t*)malloc(sizeof(tree_t));
   assert(node != NULL);
   
   node->key = key;
   node->left= node->right = NULL;
   
   node->parent = NULL; //be careful here...
   
   return node;   
}
/*============================================================================*/
void tree_insert(bst_t **t, item_t key){
  tree_t *y = NULL;
  tree_t *x = (*t)->root;
  
  while(x != NULL){
      y = x;
      if(key < x->key){
	  x = x->left;
      }else{
	  if(key == x->key){ //node already exists	    
	    printf("Sorry... ! key: %2d already exists\n", key);
	    return; //
	  }
	
	  x = x->right;
      }
  }
  
  printf("Adding key: %2d\n", key);
  tree_t *node = tree_create_node(key);
  
  node->parent = y;
  
  if(y == NULL){ //an empty tree case
      (*t)->root = node;
  }else{
      if(node->key < y->key){
	  y->left = node;
      }else{
	y->right = node;
      }
  }  
}
/*============================================================================*/
tree_t *tree_search(tree_t **t, item_t item){
    
    if(*t == NULL){
        return NULL;
    }
    if((*t)->key == item){
        return *t;
    }
    
    if(item < (*t)->key) {
        return tree_search(&((*t)->left), item);
    }else{
        return tree_search(&((*t)->right), item);
    }
}
/*============================================================================*/
tree_t *tree_search2(tree_t *t, item_t item){
    
    tree_t *h = t;
    
    while((h != NULL) && (h->key != item)){
	if(item  < h->key){
	  h = h->left;
	}else{
	  h = h->right;
	}
    }

    return h;
}
/*============================================================================*/
tree_t *tree_min_max(tree_t *t, options_t option){
    tree_t *t_ptr;
    
    if(t == NULL){
        return NULL;
    }
    
    assert((option == TREE_MIN) || (option == TREE_MAX));
    
    t_ptr = t;
    if(option == TREE_MIN){
        while(t_ptr->left != NULL){
            t_ptr = t_ptr->left;
        }
    }else{
        while(t_ptr->right != NULL){
            t_ptr = t_ptr->right;
        }        
    }
    
    return t_ptr;
}
/*============================================================================*/
tree_t *tree_min(tree_t *t){
    tree_t *t_ptr;
    
    if(t == NULL){
        return NULL;
    }
    
    t_ptr = t;

    while(t_ptr->left != NULL){
        t_ptr = t_ptr->left;
    }
    
    return t_ptr;
}
/*============================================================================*/
tree_t *tree_max(tree_t *t){
    tree_t *t_ptr;
    
    if(t == NULL){
        return NULL;
    }
    

    t_ptr = t;

    while(t_ptr->right != NULL){
        t_ptr = t_ptr->right;
    }        
    
    return t_ptr;
}
/*============================================================================*/
tree_t *tree_successor(tree_t **t){
  tree_t *h, *y;
  
  h = *t;
  if(h->right != NULL){
     return tree_min(h->right);
  }
  y = h->parent;
  
  while((y != NULL) && (h == y->right)){
     h = y;
     y = y->parent;
  }
  
  return y;
}
/*============================================================================*/
void tree_transplant(bst_t **t, tree_t *u, tree_t *v){
  
    if(u->parent == NULL){
      (*t)->root = v;
    }else{
	if(u == u->parent->left){
	  u->parent->left = v;
	}else{
	  u->parent->right = v;
	}
    }
    if(v != NULL){
      v->parent = u->parent;
    }  
}
/*============================================================================*/
int tree_delete(bst_t **t, item_t key){
  bst_t  *tp = *t;
  tree_t *y = NULL;
  tree_t *node = tree_search2(tp->root , key);
    
    if(node == NULL){
      printf("%2d not found\n", key);
      return 0;
    }
  
    if(node->left == NULL){
	tree_transplant(&tp, node, node->right);
    }else{
	if(node->right == NULL){
	    tree_transplant(&tp, node, node->left);
	}else{
	    y = tree_min(node->right);
	  
	    if(y->parent != node){
		tree_transplant(&tp, y, y->right);
	    
		y->right = node->right;
		y->right->parent = y;
	    }
	  
	    tree_transplant(&tp, node, y);
	    y->left = node->left;
	    y->left->parent = y;
	}
    }  
    
    //delete/free memory here..
    //printf("%2d found and deleted\n", key);
    
    free(node);
    
    return 1;
}
/*============================================================================*/
/*============================================================================*/
void tree_pre_order(tree_t *t){
  
  if(t != NULL){
    printf("%2d%s", t->key, (t->parent == NULL)?"r ":" ");  
    tree_pre_order(t->left);
    tree_pre_order(t->right);
  }  
}
/*============================================================================*/
void tree_in_order(tree_t *t){
  if(t != NULL){
    tree_in_order(t->left);
    printf("%2d%s", t->key, (t->parent == NULL)?"r ":" ");    
    tree_in_order(t->right);
  }    
}
/*============================================================================*/
void tree_post_order(tree_t *t){
  if(t != NULL){
    tree_post_order(t->left);       
    tree_post_order(t->right);
    printf("%2d%s", t->key, (t->parent == NULL)?"r ":" ");  
  }   
}
/*============================================================================*/

/*============================================================================*/

/*============================================================================*/
int main(){
  int  values [] = {15,7,18,5,8,17,21};
  
  int N = sizeof(values)/sizeof(values[0]);
  
  bst_t *T = (bst_t*)malloc(sizeof(bst_t));
  
  T->root = NULL; //set root of the tree to NULL
  
  tree_insert(&T, 15);
  tree_insert(&T, 7);
  tree_insert(&T, 18);
  tree_insert(&T, 5);
  tree_insert(&T, 8);
  tree_insert(&T, 17);
  tree_insert(&T, 21);  
  tree_insert(&T, 8); 
  
  printf("=======================================");
  printf("\nPRE-Order: ");
  tree_pre_order(T->root);
  printf("\nIN-Order: ");
  tree_in_order(T->root);
  printf("\nPOST-Order: ");
  tree_post_order(T->root);
  printf("\n=======================================\n");
  printf("\n");
  
  
  /*tree_delete(&T, 18);
  printf("New Tree: ");
  tree_pre_order(T->root);  
  printf("\n");*/
  
  int i;
  for(i= 0; i < N; i++){
    tree_delete(&T, values[i]);
    printf("deleting %2d -> New Tree: ",values[i]);
    tree_in_order(T->root);
    printf("\n");
  }
  
  tree_delete(&T, 12);
  
  free(T);
  
  return 0;
}