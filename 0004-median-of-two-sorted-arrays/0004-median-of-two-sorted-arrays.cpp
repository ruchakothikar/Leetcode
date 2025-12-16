class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }
    double median;
    int sum = nums1.size()+nums2.size();
    int half = (sum+1)/2;
    int left = 0;
    int right = nums1.size();
    int cut1 = (left+right)/2;
    int cut2 = half - cut1;
    int l1 = (cut1==0)?INT_MIN:nums1[cut1-1];
    int r1 = (cut1==nums1.size())?INT_MAX:nums1[cut1];
    int l2 = (cut2==0)?INT_MIN:nums2[cut2-1];
    int r2 = (cut2==nums2.size())?INT_MAX:nums2[cut2];
    while(l1>r2 || l2>r1)
    {
        if(l1>r2)
        {
            right = cut1-1;
        }
        else
        {
            left = cut1+1;
        }
        cut1 = (left+right)/2;
        cut2 = half - cut1;
        l1 = (cut1==0)?INT_MIN:nums1[cut1-1];
        r1 = (cut1==nums1.size())?INT_MAX:nums1[cut1];
        l2 = (cut2==0)?INT_MIN:nums2[cut2-1];
        r2 = (cut2==nums2.size())?INT_MAX:nums2[cut2];
    }
    if(sum%2!=0)
    {
        median = max(l1, l2);
    }
    else
    {
        median = (max(l1, l2) + min(r1, r2))/2.0;
    }
    return median;
    }
};