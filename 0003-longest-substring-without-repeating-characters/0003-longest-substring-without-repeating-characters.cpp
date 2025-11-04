class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dupe;
        int c=0;
        int res=0;
        int start = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(dupe.count(s[i]))
            {
                start = max(start, dupe[s[i]] + 1);
            }
            dupe[s[i]] = i;
            res = max(res, i - start + 1);
        }
        return res;
    }
};