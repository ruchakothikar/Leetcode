class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        for(int i=0; i<tokens.size(); i++)
        {   
            int temp=0;
            int temp2=0;
            if(tokens[i]=="+")
            {
                temp = op.top();
                op.pop();
                temp2 = op.top();
                op.pop();
                op.push(temp2+temp);
            }
            else if(tokens[i]=="-")
            {
                temp = op.top();
                op.pop();
                temp2 = op.top();
                op.pop();
                op.push(temp2-temp);
            }
            else if(tokens[i]=="*")
            {
                temp = op.top();
                op.pop();
                temp2 = op.top();
                op.pop();
                op.push(temp2*temp);
            }
            else if(tokens[i]=="/")
            {
                temp = op.top();
                op.pop();
                temp2 = op.top();
                op.pop();
                op.push(temp2/temp);
            }
            else
            {
                op.push(stoi(tokens[i]));
            }
        }
        return op.top();
    }
};