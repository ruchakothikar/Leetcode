/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr)
        {
            return "[]";
        }
        vector<string> code;
        queue<TreeNode*> q;
        string serial;
        q.push(root);
        //putting tree values into vector
        while(!q.empty())
        {
            if(q.front()==nullptr)
            {
                code.push_back("null");
            }
            else
            {
                code.push_back(to_string(q.front()->val));
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        //removing trailing nulls
        while(!code.empty() && code.back()=="null")
        {
            code.pop_back();
        }
        //turning vector into string
        serial+="[";
        for(int i=0; i<code.size(); i++)
        {
            serial+=code[i];
            serial+=",";
        }
        serial.pop_back();
        serial+="]";
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //edge case for empty string
        if(data=="[]")
        {
            return nullptr;
        }
        data = data.substr(1, data.size()-2);
        vector<string> vec;
        queue<TreeNode*> q;
        string item;
        stringstream ss(data);
        //moving values from string to vector
        while(getline(ss, item, ','))
        {
            vec.push_back(item);
        }
        //initializing root node
        TreeNode* root = new TreeNode(stoi(vec[0]));
        //putting root in queue
        q.push(root);
        int i=1;
        //putting left and right children into tree
        while(!q.empty() && i<vec.size())
        {
            TreeNode* parent = q.front();
            q.pop();
            if(i<vec.size() && vec[i]!="null")
            {
                parent->left = new TreeNode(stoi(vec[i]));
                q.push(parent->left);
            }
            i++;
            if(i<vec.size() && vec[i]!="null")
            {
                parent->right = new TreeNode(stoi(vec[i]));
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));