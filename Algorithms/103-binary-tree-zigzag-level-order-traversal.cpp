/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        q.push(root);

        bool leftRight = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                int index = leftRight ? i : (n - 1 - i);
                temp[index] = curr->val;
                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            leftRight = !leftRight;
            ans.push_back(temp);
        }
        return ans;
    }
};