class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i=0, j=0, n1=nums1.size(), n2=nums2.size();
        while(i<n1 && j<n2)
        {
            if(nums1[i] <= nums2[j])
            {
                nums.push_back(nums1[i]);
                i += 1;
            }
            else
            {
                nums.push_back(nums2[j]);
                j += 1;
            }
        }
        while(i<n1)
        {
            nums.push_back(nums1[i]);
            i += 1;
        }
        while(j<n2)
        {
            nums.push_back(nums2[j]);
            j += 1;
        }
        int n = n1+n2;
        if(n%2 == 1)
        {
            return double(nums[n/2]);
        }
        else
        {
            return double(nums[n/2-1]+nums[n/2])/2.0;
        }
    }
};
