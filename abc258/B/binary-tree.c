/* 2013 */
/* gcc -lm -Wall -O2 binary-tree.c -o binary-tree */
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE_TYPE;

/* ------------------------------------------ */
void tree_display(NODE_TYPE* node, int level) {
  int i;

  if( node != NULL ) {
    tree_display(node->right, level+1);
    printf("\n");   
    for(i=0; i<level; i++) {
      printf("__");
     }
    printf("%d", node->data);
    tree_display( node->left, level+1);
  }
}

/* ------------------------------------------ */
NODE_TYPE* tree_find_min(NODE_TYPE* node) {
  if( (node == NULL) || (node->left == NULL) ) {
    return node;
  }
  return tree_find_min(node->left);
}

/* ------------------------------------------ */
NODE_TYPE* tree_find_max(NODE_TYPE* node) {
  if( (node==NULL) || (node->right==NULL) ) {
    return node;
  }
  return tree_find_max(node->right);
}

/* ------------------------------------------ */
NODE_TYPE* tree_find(NODE_TYPE* node, int data) {
  if(node==NULL) {
    return NULL;
  }
  if( data <  (node->data)) {
    return tree_find(node->left, data);
  }
  if( data >  (node->data) ) {
    return tree_find(node->right, data);
  }
  return node;
}

/* ------------------------------------------ */
NODE_TYPE* tree_find_nonrecursion(NODE_TYPE* root, int data) {
  NODE_TYPE *node;

  node = root;
  while ( node != NULL ) {
    if ( data == node->data ) {
       return node;
     }
    else if ( data < (node->data) ) {
       node = node->left;
     }
    else {
       node = node->right;
     }
  } 
  return NULL;
}

/* ------------------------------------------ */
NODE_TYPE* tree_insert(NODE_TYPE* node, int data) {
  if (node==NULL) {
    if ( NULL == ( node = malloc(sizeof(NODE_TYPE)))) {
      printf("\nERROR: Can not allocate memory");
      exit(-1);
     }
    node->left = NULL;
    node->right = NULL;
    node->data  = data;
  }
  else {
    if ( data < node->data ) {
       node->left = tree_insert( node->left, data );
     }
    else if ( data > node->data ) {
       node->right = tree_insert( node->right, data );
     }
  }
  return node;
}

/* ------------------------------------------ */
NODE_TYPE* tree_delete(NODE_TYPE* node, int data) {
  NODE_TYPE* temp;

  if(node == NULL) {
    printf("\nData item not found");
  }
  else if(data < node->data) {
    node->left = tree_delete(node->left, data);
  } 
  else if (data > node->data) {
    node->right = tree_delete(node->right, data);
  }
  else {
    if((node->left) && (node->right)) {
      temp = tree_find_min(node->right);
      node->data = temp->data;
      node->right = tree_delete(node->right, node->data);
    }
    else if(node->left == NULL) {
      node=node->right;
    }
    else {
      node=node->left;
    }
  }
  return node;
}

/* ------------------------------------------ */
int main(int argc, char** argv) {
  NODE_TYPE *root;
  int i, v;

  root = NULL;
  printf("\nRandom numbers:\n");
  for(i=0; i<10; i++) {
     v = rand() %  100 ;
     printf("%2d ", v );
     root = tree_insert( root,  v );
   }
  printf("\n\n\n*** Tree ***");
  tree_display(root, 0);
  printf("\n\n\n*** Delete 35 *** ");
  tree_delete( root, 35 );
  printf("\n\n\n*** Tree ***");
  tree_display(root, 0);

  return 0;
}


