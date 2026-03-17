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
    bool dfs(TreeNode* node, long minlim, long maxlim)
    {
        if(node==nullptr)
        {
            return true;
        }
        if(node->val >= maxlim || node->val <= minlim)
        {
            return false;
        }
        return (dfs(node->left, minlim, node->val) && dfs(node->right, node->val, maxlim));
    }
    bool isValidBST(TreeNode* root) {
        long maxlim = LONG_MAX;
        long minlim = LONG_MIN;
        return dfs(root, minlim, maxlim);
    }
};