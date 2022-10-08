// 958. Check Completeness of a Binary Tree
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

int countNode(TreeNode* root) {

    if(root == NULL)
        return 0;
    
    return (1 + countNode(root->left) + countNode(root->right));
}

bool solve(TreeNode* root, int index, int& totalNodes) {

    if(root == NULL)
        return true;

    if(index >= totalNodes)
        return false;

    else {
        bool left = solve(root->left, index*2+1, totalNodes);
        bool right = solve(root->right, index*2+2, totalNodes);

        return left && right;
    }
}

bool isCompleteTree(TreeNode* root) {
    int totalNodes = countNode(root);
    return solve(root, 0, totalNodes);    
}