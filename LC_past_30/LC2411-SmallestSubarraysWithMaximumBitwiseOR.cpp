class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> nearest(32, 0);
        vector<int> result;
        int n = nums.size();
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<32; j++)
            {
                if((nums[i] & (1<<j)) != 0)
                    nearest[j] = i;
            }
            int farthest = i;
            for(int k=0; k<32; k++)
            {
                farthest = max(farthest, nearest[k]);
            }
            result.push_back(farthest-i+1);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
