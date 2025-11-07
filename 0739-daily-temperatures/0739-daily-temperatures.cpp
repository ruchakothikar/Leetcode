class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> ind;
        vector<int> res(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++)
        {
            while(!ind.empty() && temperatures[i]>temperatures[ind.top()])
            {
                res[ind.top()] = i-ind.top();
                ind.pop();
            }
            ind.push(i);
        }
        while(!ind.empty())
        {
            res[ind.top()] = 0;
            ind.pop();
        }
        return res;
    }
};