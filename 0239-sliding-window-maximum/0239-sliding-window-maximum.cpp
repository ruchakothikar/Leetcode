class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> track;
        vector<int> res;
        for(int i=0; i<nums.size(); i++)
        {
                if(!track.empty() && track.front()<=i-k)
                {
                    track.pop_front();
                }
                while(!track.empty() && nums[track.back()]<=nums[i])
                {
                    track.pop_back();
                }
                track.push_back(i);
                if(i>=k-1)
                {
                res.push_back(nums[track.front()]);
                }
        }
        return res;
    }
};