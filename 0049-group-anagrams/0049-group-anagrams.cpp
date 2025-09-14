class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;
        for(int i=0; i<strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            anagram[temp].push_back(strs[i]);    
        }
        vector<vector<string>> res;
        for(auto it=anagram.begin(); it!=anagram.end(); it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};