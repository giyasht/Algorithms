
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left,*right;
};

struct node* newNode(int item){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->key=item;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void inorder(struct node* root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

struct node* insert(struct node* node,int key){
    if(node==NULL){
        return newNode(key);
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else{
        node->right=insert(node->right,key);
    }
    return node;
}
void subRightView(struct node* node,int l,int *m){
    if(node==NULL){
        return;
    }
    if(*m<l){
        printf("%d  ",node->key);
        *m=l;
    }
    subRightView(node->right,l+1,m);
    subRightView(node->left,l+1,m);
}

void rightView(struct node* root){
    int m=0;
    subRightView(root,1,&m);
}

void treesum(struct node* node,int *sum){
    if(node==NULL){
        return;
    }
    treesum(node->right, sum);
    *sum=*sum+ node->key;
    node->key=*sum-node->key;
    treesum(node->left,sum);
}

void transformTree(struct node* root){
    int sum=0;
    treesum(root,&sum);
}

void evenSort(int a[],int n,int i){
    for (int j = i+2; j < n; j+=2)
    {
        int key = a[j];
        int k = j - 2;
        while (key > a[k] && k >= 0)
        {
            a[k + 2] = a[k];
            k-=2;
        }
        a[k + 2] = key;
    }
}

void oddSort(int a[],int n,int i){
    for (int j = i+2; j < n; j+=2)
    {
        int key = a[j];
        int k = j - 2;
        while (key < a[k] && k >= 0)
        {
            a[k + 2] = a[k];
            k-=2;
        }
        a[k + 2] = key;
    }
}

void sortOddEven(int a[],int n){
    evenSort(a,n,0);
    oddSort(a,n,1);
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    inorder(root);
    printf("\n");
    rightView(root);
    printf("\n");
    transformTree(root);
    inorder(root);
    printf("\n");
    int n=9;
    int a[]={7,10,11,3,6,9,2,13,0};
    sortOddEven(a,n);
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}
