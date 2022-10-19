class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2], res = 0;
        for(int i: nums)
            res += (abs(i-median));
        return res;
    }
};
