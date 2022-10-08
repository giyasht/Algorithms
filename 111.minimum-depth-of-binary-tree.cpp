// 111. Minimum Depth of Binary Tree
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

int minDepth(TreeNode* root) {

    if(root == NULL) 
        return 0;

    int d1 = 1 + minDepth(root->right);
    
    int d2 = 1 + minDepth(root->left);
    
    int p = min(d1,d2);

    if(p > 1) return p;
        
    return max(d1,d2);
}