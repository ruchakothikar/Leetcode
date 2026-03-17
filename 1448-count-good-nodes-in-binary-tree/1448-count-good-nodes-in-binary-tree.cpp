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
    void dfs(TreeNode* node, int largest, int& good)
    {
        //base case
        if(node==nullptr)
        {
            return;
        }
        //checking if node is good
        if(node->val >= largest)
        {
            good++;
        }
        //updating max value
        largest = max(largest, node->val);
        //recursion
        dfs(node->left, largest, good);
        dfs(node->right, largest, good);
    }
    int goodNodes(TreeNode* root) {
        int largest = root->val -1;
        int good = 0;
        dfs(root, largest, good);
        return good;
    }
};