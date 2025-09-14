#include <limits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int mini = prices[0];
       for(int i=1; i<prices.size();i++)
       {
        if (prices[i]<mini)
        {
            mini = prices[i];
            continue;
        }
        if((prices[i]-mini)>profit)
        {
            profit = prices[i]-mini;
        }
       }
       return profit;
    }
};
















/* int profit=0, min=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
                continue;
            }
            if((prices[i]-min)>profit)
            profit = prices[i]-min;
        }
        return profit;

        */