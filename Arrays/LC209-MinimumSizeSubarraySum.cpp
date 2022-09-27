class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimum = INT_MAX, n = nums.size(), j = 0, i = 0, sum = 0;
        while(j<n)
        {
            sum += nums[j];
            j++;
            while(sum >= target)
            {
                minimum = min(minimum, j-i);
                sum -= nums[i++];
            }
        }
        return minimum == INT_MAX ? 0 : minimum;
    }
};
