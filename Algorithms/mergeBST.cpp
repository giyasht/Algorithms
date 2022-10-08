#include<iostream>
#include<vector>
using namespace std;
 class Node {
    public : 
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        ~Node() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };
void inorderTraverse(Node *root, vector<int> &in){
    if(root == NULL)
        return;
    inorderTraverse(root -> left,in);
    in.push_back(root -> data);
    inorderTraverse(root -> right,in);
}
//merge function
vector<int> mergeArray(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i=0;
    int j = 0;
    int k = 0;
    
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    
    while(i < a.size()){
        ans[k++] = a[i];
        i++;
    }
    
    while(j < b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

//inordertoBST
Node *inorderToBST(int s,int e, vector<int> &in){
    //base case
    if(s>e){
        return NULL;
    }
    
    int mid = (s+e)/2;
    Node *root = new Node(in[mid]);
    //left call
    root -> left = inorderToBST(s,mid-1,in);
    //right call
    root -> right = inorderToBST(mid+1,e,in);
    return root;
}

Node *mergeBST(Node *root1, Node *root2){
    //store inorder of both BST
    vector<int> bst1,bst2;
    inorderTraverse(root1,bst1);
    inorderTraverse(root2,bst2);
    
    //merge call
    vector<int> mergedArray = mergeArray(bst1,bst2);
    int s = 0, e = mergedArray.size() - 1;
    return inorderToBST(s,e,mergedArray);
}