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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case: if both nodes are null then true
        if(p==nullptr && q==nullptr)
        {
            return true;
        }
        //base case: if one node is null then false (we aleady checked for both null)
        else if(p==nullptr || q==nullptr)
        {
            return false;
        }
        //comparison in values, if differ then false
        if(p->val!=q->val)
        {
            return false;
        }
        //recursive call to left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};