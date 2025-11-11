class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k, mid, lower = 1, upper = *max_element(piles.begin(), piles.end());
        long long hours;
        k  = upper;
        while(lower<=upper)
        {
            hours = 0;
            mid = (upper+lower)/2;
            for(int i=0; i<piles.size(); i++)
            {
                hours+= (int)ceil((double)piles[i]/mid);
            }
            if(hours<=h)
            {
                upper = mid-1;
                k = min(k, mid);
            }
            else
            {
                lower = mid+1;
            }
        }
        return k;
    }
};