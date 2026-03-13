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
//writing dfs
    int dfs(TreeNode* node, int &max_diameter)
    {
        if (!node)
        {
            return 0;
        }
        int leftheight = dfs(node->left, max_diameter);
        int rightheight = dfs(node->right, max_diameter);
        max_diameter = max(max_diameter, leftheight + rightheight);
        return 1+ max(leftheight, rightheight);
    }
    //defining max diameter and calling separate dfs function
    int diameterOfBinaryTree(TreeNode* root) {
         int max_diameter = 0;
        dfs(root, max_diameter);
        return max_diameter;
    }
};