class Solution {
public:
    bool isPalindrome(string s) {
        int c=0;
        string comp;
        int j;
        for(int i=0; i<s.length(); i++)
        {
            if((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
            {
                comp.push_back(s[i]);
            }
        }
        for (int i = 0, j=comp.length()-1; i < comp.length(); i++, j--)
        {   
            if(j<i)
            {
                break;
            }
            comp[i] = tolower(comp[i]);
            comp[j] = tolower(comp[j]);
            if(comp[i]!=comp[j])
                return false;
        }
        return true;
    }
};