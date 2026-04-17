/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* postorder(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        //base case
        if(!root)
        {
            return nullptr;
        }
        //checking current node
        if(root==p || root==q)
        {
            return root;
        }
        //storing results of left and right subtrees
        TreeNode* leftResult = postorder(root->left, p, q);
        TreeNode* rightResult = postorder(root->right, p, q);
        //checking if both subtrees returned non null values
        if(leftResult && rightResult)
        {
            return root;
        }
        //returning non null side or null if both are null
        return leftResult ? leftResult : rightResult;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return postorder(root, p, q);
    }
};