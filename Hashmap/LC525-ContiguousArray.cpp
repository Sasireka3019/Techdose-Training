class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        map<int, int> mp;
        int count = 0, index = -1, maxlen = 0;
        mp[0] = -1;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1)
                count += 1;
            else
                count -= 1;
            if(mp.find(count) != mp.end())
                maxlen = max(maxlen, i-mp[count]);
            else
                mp[count] = i;
        }
        return maxlen;
    }
};
