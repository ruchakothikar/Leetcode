class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        vector<vector<int>> buckets(nums.size()+1);
        for(int i=0; i<nums.size(); i++)
        {
            if(freq.count(nums[i]))
            {
                freq[nums[i]]++;
            }
            else
            {
                freq.insert({nums[i], 1});
            }
        }
        for(auto it=freq.begin(); it!=freq.end(); it++)
        {
            buckets[it->second].push_back(it->first);
        }
        vector<int> res;
        for(int i=nums.size(); i>=1 && res.size()<k; i--)
        {
            for(int j=0; j<buckets[i].size() && res.size()<k; j++)
            {
                res.push_back(buckets[i][j]);
            }
        }
        return res;
    }
};