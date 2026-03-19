class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int start =0, end = 0;
        int maxfreq = 0;
        int res = 0;
        for(end=0; end<s.length(); end++)
        {
            freq[s[end]]++;
            maxfreq = max(maxfreq, freq[s[end]]);
            while((end-start+1)-maxfreq>k)
            {
                freq[s[start]]--;
                start++;
            }
                res = max(res, end-start+1);
        }
        return res;
    }
};