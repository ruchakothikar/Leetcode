class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices_by_value;
        vector<int> res; 
        for (int i = 0; i < nums.size(); i++) {
            int complement = target-nums[i];

            if (indices_by_value.find(complement) != indices_by_value.end()) {
                res.push_back(indices_by_value[complement]);
                res.push_back(i);
                break;
            }

            indices_by_value[nums[i]] = i;
        }
        return res;
    }
};