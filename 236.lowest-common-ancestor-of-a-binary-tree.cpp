// 112. Path Sum
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree() {

    int n;
    cin >> n;

    if(n == -1) {
        return NULL;
    }

    Node* root = new Node(n);

    root->left = buildTree();

    root->right = buildTree();

    return root;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    
    if(root == NULL)
        return root;

    if(root == p || root == q)
        return root;
        
    else {
        Node* leftAns = lowestCommonAncestor(root->left, p, q);
        Node* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns != NULL && rightAns != NULL)
            return root;
            
        else if(leftAns == NULL)
            return rightAns;
        else
            return leftAns;
    }
}

int main() {

    Node* root = buildTree();

    Node* p = new Node(5);
    Node* q = new Node(1);

    Node* ans = lowestCommonAncestor(root, p, q);

    cout << ans->data << endl;

    return 0;
}