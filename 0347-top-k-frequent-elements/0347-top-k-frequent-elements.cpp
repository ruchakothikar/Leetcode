class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> res;
        //storing numbers and counts in map
        for(int i=0; i<nums.size(); i++)
        {
            if(!freq.count(nums[i]))
            {
            freq[nums[i]] = 1;
            }
            else
            {
                freq[nums[i]]++;
            }
        }
        //storing counts and numbers in heap
        for(auto it=freq.begin(); it!=freq.end(); it++)
        {
            pq.push({it->second, it->first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        //storing top k frequent elements in vector to return
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};