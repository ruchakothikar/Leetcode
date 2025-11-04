class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i, lower=0, upper=nums.size()-1;
        while(lower<=upper)
        {
            i = (lower+upper)/2;
            if(nums[i]==target)
            {   
                return i;
            }
            else if(nums[i]<target)
            {
                lower = i+1;
            }
            else if(nums[i]>target)
            {
                upper = i-1;
            }
        }
        return -1;
    }
};