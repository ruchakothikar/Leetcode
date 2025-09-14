class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        vector<int> res;
        left.push_back(1);
        right.push_back(1);
        for(int i=1; i<nums.size(); i++)
        {
            left.push_back(left[i-1]*nums[i-1]);
            right.push_back(right[i-1]*nums[nums.size()-i]);
        }
        for(int i=1; i<=nums.size(); i++)
        {
            res.push_back(right[nums.size()-i]*left[i-1]);
        }
        return res;
    }
};