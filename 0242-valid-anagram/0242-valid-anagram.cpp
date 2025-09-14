class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> anagram;
        for(int i=0; i<t.size(); i++)
        {
            if(anagram.count(t[i]))
            {
                anagram[t[i]]++;
            }
            else
            {
                anagram.insert({t[i], 1});
            }
        }
        for(int j=0; j<s.size(); j++)
        {
            if(anagram.count(s[j]))
            {
                anagram[s[j]]--;
            }
            else
            {
                return false;
            }
        }
        for(int i=0; i<t.size(); i++)
        {
            if(anagram[t[i]]!=0)
                return false;
        }
        return true;
    }
};