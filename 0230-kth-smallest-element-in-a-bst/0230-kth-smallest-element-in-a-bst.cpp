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
class Solution {
public:
    void dfs(TreeNode* root, int k, int& ans, int& c)
    {
        //base case
        if(root==nullptr)
        {
            return;
        }
        dfs(root->left, k, ans, c);
        c++;
        if(c==k)
        {
            ans = root->val;
            return;
        }
        dfs(root->right, k, ans, c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int ans = -1;
        dfs(root, k, ans, c);
        return ans;
    }
};