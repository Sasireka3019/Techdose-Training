class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,maxReach = 0, n = nums.size();
        for(i=0; i<n && i<=maxReach; i++)
        {
            maxReach = max(maxReach, nums[i]+i);
        }
        if(i == n)
            return true;
        else
            return false;
    }
};    
