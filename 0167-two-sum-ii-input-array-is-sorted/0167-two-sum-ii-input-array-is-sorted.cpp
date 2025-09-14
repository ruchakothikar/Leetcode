class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        vector<int> res;
        while(numbers[i]+numbers[j]!=target)
        {
            if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else if(numbers[i]+numbers[j]<target)
            {
                i++;
            }
        }
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
    }
};