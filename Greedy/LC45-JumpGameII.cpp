class Solution {
public:
    int jump(vector<int>& nums) {
	    int n = nums.size(), currEnd = 0, currFarthest = 0, jumps = 0;
        for(int i=0; i<n-1; i++)
        {
            currFarthest = max(currFarthest, i+nums[i]);
            if(i == currEnd)
            {
                currEnd = currFarthest;
                jumps += 1;
            }
        }
        return jumps;
    }
};
