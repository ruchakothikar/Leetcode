class Solution {
public:
    string minWindow(string s, string t) {
         int l=0, minimum = s.size()+1, sat=0, minLeft=0;
        unordered_map <char, int> check;
        //adding t characters to map
        for(int i=0; i<t.size(); i++)
        {
            check[t[i]]++;
        }
        //outer loop to traverse s
        for(int r=0; r<s.size(); r++)
        {
            //if char exists in t, reducing need count in map
            if(check.count(s[r]))
            {
                check[s[r]]--;
            }
            //checking if a character is satisfied
            if(check.count(s[r]) && check[s[r]]==0)
            {
                sat++;
            }
            //shrinking
            while(sat==check.size())
            {
                if(check.count(s[l]))
                {
                    check[s[l]]++;
                }
                //updating minimum window
                if((r-l+1) < minimum)
                {
                    minimum = r-l+1;
                    minLeft = l;
                }
                if(check.count(s[l]) && check[s[l]]==1)
                {
                    sat--;
                }
                l++;
            }
        }
        //if no window is satisfactory
        if(minimum>s.length())
        {
            return "";
        }
        return s.substr(minLeft, minimum);
    }
};