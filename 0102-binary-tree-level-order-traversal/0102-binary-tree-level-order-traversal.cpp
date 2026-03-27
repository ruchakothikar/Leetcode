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
    vector<vector<int>> levelOrder(TreeNode* root) {
         queue<TreeNode*> q;
        vector<vector<int>> res;
        //base case: if root is null then return res
        if(!root)
        {
            return res;
        }
        //adding root to queue
        q.push(root);
        while(!q.empty())
        {
            //checking number of nodes on current level
            int levelSize = q.size();
            vector<int> level;
            //making sublist, adding children to queue
            for(int i=0; i<levelSize; i++)
            {
                level.push_back(q.front()->val);
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            //adding sublist to result list
            res.push_back(level);
        }
        return res;
    }
};