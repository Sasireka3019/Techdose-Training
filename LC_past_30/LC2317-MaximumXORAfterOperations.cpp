class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int number = *max_element(nums.begin(), nums.end()), till = 0;
        if(number != 0)
            till = (int)log2(number)+1;
        int res = 0, pow = 1;
        for(int i=0; i<till; i++)
        {
            int count = 0;
            for(int x : nums)
            {
                if((x&(1<<i)) != 0)
                {
                    count++;
                }
            }
            if(count > 0)
                res += pow;
            pow *= 2;
        }
        return res;
    }
};
