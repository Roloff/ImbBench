struct bst_node 
{ 
    int key; 
    struct bst_node *left, *right; 

    char *szFill[]; 
}; 
   
struct bst_node *bst_newNode(int key);
   
struct bst_node* bst_insert(struct bst_node* node, int key);

struct bst_node* bst_search(struct bst_node* root, int key);

void bst_inorder(struct bst_node *root);
