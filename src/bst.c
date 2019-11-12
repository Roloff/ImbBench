#include<stdio.h> 
#include<stdlib.h> 

#define NO_DEBUG

#ifndef DEBUG
#include "bst.h" 
#endif


#ifdef DEBUG
#define TAM_BST 100000

struct bst_node 
{ 
    int key; 
    struct bst_node *left, *right; 
}; 

struct bst_node *bst_newNode(int key);
struct bst_node* bst_insert(struct bst_node* node, int key);
struct bst_node* bst_search(struct bst_node* root, int key);
void bst_inorder(struct bst_node *root);

#endif
   
struct bst_node *newNode(int item) 
{ 
    struct bst_node *temp =  (struct bst_node *)malloc(sizeof(struct bst_node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
struct bst_node* bst_insert(struct bst_node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = bst_insert(node->left, key); 
    else if (key > node->key) 
        node->right = bst_insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

struct bst_node* bst_search(struct bst_node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return bst_search(root->right, key); 
  
    // Key is smaller than root's key 
    return bst_search(root->left, key); 
} 

void bst_inorder(struct bst_node *root) 
{ 
    if (root != NULL) 
    { 
        bst_inorder(root->left); 
        printf("%d \n", root->key); 
        bst_inorder(root->right); 
    } 
} 

#ifdef DEBUG
int main()
{
    struct bst_node *root = NULL; 

    root = bst_insert(root, TAM_BST/2); 

    for (int i=0;i<TAM_BST;i++)
        bst_insert(root, i); 
}
#endif