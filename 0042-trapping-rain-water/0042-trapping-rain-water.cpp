class Solution {
public:
    int trap(vector<int>& height) {
        int maxL = height[0];
        int maxR = height[height.size()-1];
        int water = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r)
        {
            if(maxL<=maxR)
            {
                if((min(maxL, maxR) - height[l])>=0)
                {
                    water+=min(maxL, maxR)-height[l];
                }
                l++;
                if(height[l]>maxL)
                {
                    maxL = height[l];
                }
            }
            else
            {
                if((min(maxL, maxR) - height[r])>=0)
                {
                    water+=min(maxL, maxR)-height[r];
                }
                r--;
                if(height[r]>maxR)
                {
                    maxR = height[r];
                }
            }
        }
        return water;
    }
};