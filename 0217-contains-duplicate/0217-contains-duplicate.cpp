class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> dupe;
        for(int i=0; i<nums.size(); i++)
        {
            if(dupe.count(nums[i]))
                return true;
            dupe[nums[i]] = nums[i];
        }
        return false;
    }
};