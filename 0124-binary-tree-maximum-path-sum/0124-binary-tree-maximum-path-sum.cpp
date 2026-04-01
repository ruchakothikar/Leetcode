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
    int post(TreeNode* root, int& most)
    {
        //base case
        if(root==nullptr)
        {
            return 0;
        }
        //recursing left and right subtrees
        int left = post(root->left, most);
        int right = post(root->right, most);
        //not counting negative values
        left = max(0, left);
        right = max(0, right);
        //updating total max
        most = max(most, left+right+root->val);
        //returning max path to parent node
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int most = INT_MIN;
        post(root, most);
        return most;
    }
};