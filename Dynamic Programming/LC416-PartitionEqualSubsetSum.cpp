class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        for(int i=0; i<=n; i++)
            dp[i][0] = true;
        for(int j=1; j<=sum; j++)
            dp[0][j] = false;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
        int search = sum/2, found = -1;
        for(int i=search; i>=0; i--)
        {
            if(dp[n][i] == true)
            {
                found = i;
                break;
            }
        }
        if(sum-2*found == 0)
            return true;
        else
            return false;
    }
};
