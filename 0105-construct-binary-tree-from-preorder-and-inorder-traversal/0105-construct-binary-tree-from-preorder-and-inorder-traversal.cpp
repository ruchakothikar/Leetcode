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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& ind)
    {
        //base case
        if(preStart>preEnd || inStart>inEnd)
        {
            return nullptr;
        }
        //root is first value of preorder
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);
        //finding root in inorder and size of left subtree
        int inRoot = ind[rootValue];
        int leftSize = inRoot-inStart;
        //call function recursively to build left and right subtrees
        root->left = build(preorder, preStart+1, preStart+leftSize, inorder, inStart, inRoot-1, ind);
        root->right = build(preorder, preStart+leftSize+1, preEnd, inorder, inRoot+1, inEnd, ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ind;
        for(int i=0; i<inorder.size(); i++)
        {
            ind[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, ind);
    }
};