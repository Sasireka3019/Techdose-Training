class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0), result;
        for(int i=0; i<n; i++)
        {
            if(i==0 || nums[i]>nums[i-1])
                left[i] = 1;
            else
                left[i] = left[i-1]+1;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1 || nums[i]>nums[i+1])
                right[i] = 1;
            else
                right[i] = right[i+1]+1;
        }
        for(int i=k; i<n-k; i++)
        {
            if(left[i-1] >= k && right[i+1] >= k)
                result.push_back(i);
        }
        return result;
    }
};
