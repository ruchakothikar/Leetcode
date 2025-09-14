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