class Solution {
public:
    bool isValid(string s) {
        std:: stack<char> stack1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            stack1.push(')');
            else if(s[i]=='{')
            stack1.push('}');
            else if(s[i]=='[')
            stack1.push(']');
            else if((s[i]==')' || s[i]=='}' || s[i]==']') && stack1.empty())
            {return false;}
            else if ((s[i]==')' || s[i]=='}' || s[i]==']') && !stack1.empty())
            {
                if(s[i]==stack1.top())
                {   stack1.pop();
                    continue;}
                else
                return false;
            }
        }
        return stack1.empty();
    }
};


//use stack
//every time there is an opening bracket, add the closing counterpart in the stack
//else compare the character to stack.top while stack is not empty. if same then continue, if mismatch then break and return false. if stack is empty then return false
//at end, if 
//if stack is not empty then return false. if empty then return true















/*std::stack<char> stack1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') {
                stack1.push(')');
            }
            else if(s[i]=='{') {
                stack1.push('}');
            }
            else if(s[i]=='[') {
                stack1.push(']');
            }
            else if (!stack1.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')) {
                if (stack1.top() == s[i]) {
                    stack1.pop();
                }
                else {
                    return false;
            }
                }
            else
            {
                return false;
            }
        }
        return stack1.empty();
        */