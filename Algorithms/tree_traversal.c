#include<stdio.h> 
#include<stdlib.h> 
  

struct NODE  
{ 
    int data; 
    struct NODE* left; 
    struct NODE* right; 
}; 

int getLevelUtil(struct NODE *NODE, int data, int level) 
{ 
    if (NODE == NULL) 
        return 0; 
  
    if (NODE->data == data) 
        return level; 
  
    int downlevel = getLevelUtil(NODE->left, data, level+1); 
    if (downlevel != 0) 
        return downlevel; 
  
    downlevel = getLevelUtil(NODE->right, data, level+1); 
    return downlevel; 
} 
  
/* Returns level of given data value */
int getLevel(struct NODE *NODE, int data) 
{ 
    return getLevelUtil(NODE,data,1); 
} 


struct NODE* newNODE(int data) 
  
{ 
  struct NODE* NODE = (struct NODE*)malloc(sizeof(struct NODE)); 
  NODE->data = data; 
  NODE->left = NULL; 
  NODE->right = NULL; 
    
  return(NODE); 
} 
  
 void preOrder(struct NODE* NODE)  
{ 
  if (NODE == NULL)  
    return; 
  printf("%d ", NODE->data); 
  preOrder(NODE->left); 
  preOrder(NODE->right); 
}    

  
  
void inOrder(struct NODE* NODE)  
{ 
  if (NODE == NULL)  
    return; 
    
  inOrder(NODE->left); 
  printf("%d ", NODE->data); 
  inOrder(NODE->right); 
}   

void postOrder(struct NODE* NODE)  
{ 
  if (NODE == NULL)  
    return; 
    
  postOrder(NODE->left); 
  postOrder(NODE->right);
  printf("%d ", NODE->data); 
}   
struct NODE* insert(struct NODE* NODE, int data) 
{ 
    
    if (NODE == NULL) return newNODE(data); 
  
   
    if (data < NODE->data) 
        NODE->left  = insert(NODE->left, data); 
    else
        NODE->right = insert(NODE->right, data); 
  

    return NODE; 
} 
  

struct NODE * minimum_value_node(struct NODE* NODE) 
{ 
    struct NODE* current = NODE; 
  
    
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
  

struct NODE* deleteNODE(struct NODE* root, int data) 
{ 
    
    if (root == NULL) return root; 
  
    
    if (data < root->data) 
        root->left = deleteNODE(root->left, data); 
  
    
    else if (data > root->data) 
        root->right = deleteNODE(root->right, data); 
  
    
    else
    { 
        
        if (root->left == NULL) 
        { 
            struct NODE *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct NODE *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        
        struct NODE* temp = minimum_value_node(root->right); 
  
       
        root->data = temp->data; 
  
        
        root->right = deleteNODE(root->right, temp->data); 
    } 
    return root; 
} 
void print_table(struct NODE* NODE)  
{ 
  if (NODE == NULL)  
    return; 
  printf("%d\t\t%d\t\t%d ", NODE->data,NODE->left->data,NODE->right->data); 
  printf("\n");
  printf("%d\t\t%d\t\t%d ", NODE->left->data,NODE->left->left->data,NODE->left->right->data); 
  
} 
  

int main() 
{ 
 //question 1

 int n,level,m,e;
  struct NODE *root = newNODE(1); 
  root->left        = newNODE(2); 
  root->right       = newNODE(3); 
  root->left->left  = newNODE(4); 
  root->left->right = newNODE(5);  

 struct NODE *root1 = NULL; 
    root1 = insert(root1, 1); 
    root1 = insert(root1, 2); 
    root1 = insert(root1, 3); 
    root1 = insert(root1, 4); 
    root1 = insert(root1, 5); 
    
    
  printf("============================preorder traversal of the constructed NODE is====================================\n"); 
  preOrder(root); 
  printf("\n");
  
  printf("============================Inorder traversal of the constructed NODE is=====================================\n"); 
  inOrder(root); 
  printf("\n"); 
  
  printf("============================postorder traversal of the constructed NODE is===================================\n"); 
  postOrder(root); 
  printf("\n"); 
  
  printf("============================enter the element to find its level==============================================\n");
   scanf("%d",&n); 
   level=getLevel(root,n);
  printf("level of given NODE is %d\n",level);
 printf("=============================Table representation of tree====================================================\n");
  printf("item\tleft child\tright child\n");
  print_table(root);
  printf("\n============================enter the element to insert in NODE============================================\n");
  scanf("%d",&m);
  root1=insert(root1,m);
  inOrder(root1); 
  printf("\n============================enter the element to delete=====================================================\n");
  scanf("%d",&e);
  root1=deleteNODE(root1,e);
   inOrder(root1); 
  return 0;   
} 