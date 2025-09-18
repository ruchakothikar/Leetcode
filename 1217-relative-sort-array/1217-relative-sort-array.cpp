class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         unordered_map<int, int> frequency;
        vector<int> temp;
        for(int i=0; i<arr1.size(); i++)
        {
            frequency[arr1[i]]++;
        }
        vector<int> res;
        for(int i=0; i<arr2.size(); i++)
        {
            for(int j=0; j<frequency[arr2[i]]; j++)
            {
                res.push_back(arr2[i]);
            }
            frequency[arr2[i]]=0;
        }
        for(auto it = frequency.begin(); it != frequency.end(); ++it)
        {
            if((it->second)>0)
            {
               for(int i=0; i<it->second; i++)
                {
                    temp.push_back(it->first);
                }
            }
        }
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++)
        {
            res.push_back(temp[i]);
        }
        return res;
    }
};