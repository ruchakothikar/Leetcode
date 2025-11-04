class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxfreq = 0;
        int res = 0;
        int window = 0;
        int r = 0;
        int l = 0;
        int i=0;
        while(r<s.length())
        {
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);
            window = r - l + 1;
            if(window-maxfreq<=k)
            {
                res = max(res, window);
            }
            else
            {
                freq[s[l]]--;
                l++;
                window = r - l + 1;
                maxfreq = 0;
                for(auto it=freq.begin(); it!=freq.end(); it++)
                {
                    maxfreq = max(maxfreq, it->second);
                }
            }
            r++;
        }
        return res;
    }
};