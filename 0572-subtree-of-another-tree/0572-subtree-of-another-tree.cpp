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
     bool dfs(TreeNode* a, TreeNode* b)
    {
        if(a==nullptr && b==nullptr)
        {
            return true;
        }
        if(b==nullptr || a==nullptr)
        {
            return false;
        }
        if(a->val!=b->val)
        {
            return false;
        }
        return (dfs(a->left, b->left) && dfs(a->right, b->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
                if(root==nullptr)
        {
            return false;
        }
        if(subRoot==nullptr)
        {
            return true;
        }
        return (dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};