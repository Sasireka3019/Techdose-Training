class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> hmap;
        int cnt = 0, n = nums.size(), sum = 0;
        hmap[sum] = 1;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(hmap.find(sum-k) != hmap.end())
            {
                cnt += hmap[sum-k];
            }
            hmap[sum] += 1;
        }
        return cnt;
    }
};
