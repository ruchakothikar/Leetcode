class Solution {
public:
    int findMin(vector<int>& nums) {
       int lower = 0, upper = nums.size()-1;
        int mid;
        while(lower<upper)
        {
            mid = (lower+upper)/2;
            if(nums[mid]>nums[upper])
            {
                lower = mid+1;
            }
            else if(nums[mid]<nums[upper])
            {
                upper = mid;
            }
        }
        return nums[lower];
    }
};