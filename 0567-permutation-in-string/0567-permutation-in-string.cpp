class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        unordered_map<char, int> comp;
        int l=0;
        int window = 0;
        if(s2.length()<s1.length())
        {
            return false;
        }
        for(int i=0; i<s1.length(); i++)
        {
            freq[s1[i]]++;
        }
        for(int i=0; i<s2.length(); i++)
        {
            comp[s2[i]]++;
            window = i-l+1;
            if(window==s1.length())
            {
                 if(freq==comp)
                {
                    return true;
                }
                comp[s2[l]]--;
                if(comp[s2[l]]==0)
                {
                    comp.erase(s2[l]);
                }
                l++;
            }
        }
        return false;
    }
};