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
    bool dfs(TreeNode* root, int target, int sum)
    {
        //add node to sum
        //check if it is leaf node
        //call children recursively
        if(!root)
        {
            return false;
        }
        sum+= root->val;
        if(!root->left && !root->right)
        {
            if(sum==target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
            return (dfs(root->left, target, sum) || dfs(root->right, target, sum));
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return dfs(root, targetSum, sum);
    }
};