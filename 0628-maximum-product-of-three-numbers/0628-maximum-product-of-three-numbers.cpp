class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int s = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[s-1]*nums[s-2]*nums[s-3], nums[0]*nums[1]*nums[s-1]); 
    }
};


//sort vector in increasing order
//return the max of either the last 3 numbers, or the first 2 and one last number















/*
 sort(nums.begin(), nums.end());
        return max((nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]), (nums[nums.size()-1]*nums[0]*nums[1]));
*/