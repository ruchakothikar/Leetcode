class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tk = tickets[k];
        int res = 0;
        for(int i=0; i<tickets.size(); i++)
        {
            if(i<=k)
            {
                res+= min(tickets[i], tk);
            }
            else
            {
                res+= min(tickets[i], tk-1);
            }
        }
        return res;
    }
};