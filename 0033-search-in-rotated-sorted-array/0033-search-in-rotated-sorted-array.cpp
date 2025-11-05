class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0, upper = nums.size()-1;
        int mid, res = -1;
        while(lower<=upper)
        {
            mid = (lower+upper)/2;
            if(nums[mid]==target)
            {
                res = mid;
                break;
            }
            else if(nums[lower]<=nums[mid])
            {
                if(target>=nums[lower] && target<nums[mid])
                {
                    upper = mid-1;
                }
                else
                {
                    lower = mid+1;
                }
            }
            else if(nums[lower]>nums[mid])
            {
                if(target>=nums[mid] && target<=nums[upper])
                {
                    lower = mid+1;
                }
                else
                {
                    upper = mid-1;
                }
            }
        }
        return res;
    }
};