class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left[n], right[n];
        int lmax = height[0], rmax = height[n-1];
        for(int i=0; i<n; i++)
        {
            if(height[i] > lmax)
            {
                lmax = height[i];
            }
            left[i] = lmax;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(height[i] > rmax)
            {
                rmax = height[i];
            }
            right[i] = rmax;
        }
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            int low;
            if(left[i]<right[i])
                low = left[i];
            else
                low = right[i];
            sum += (low-height[i]);
        }
        return sum;
    }
};
