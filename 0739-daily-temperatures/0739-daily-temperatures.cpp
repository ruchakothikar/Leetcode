class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> ind;
        int res[temperatures.size()];
        vector<int> arr;
        for(int i=0; i<temperatures.size(); i++)
        {
            if(ind.empty() || temperatures[i]<=temperatures[ind.top()])
            {
                ind.push(i);
            }
            else if(temperatures[i]>temperatures[ind.top()])
            {
                while(!ind.empty() && temperatures[i]>temperatures[ind.top()])
                {
                    res[ind.top()] = i-ind.top();
                    ind.pop();
                }
                ind.push(i);
            }
        }
        while(!ind.empty())
        {
            res[ind.top()] = 0;
            ind.pop();
        }
        for(int i=0; i<temperatures.size(); i++)
        {
            arr.push_back(res[i]);
        }
        return arr;
    }
};