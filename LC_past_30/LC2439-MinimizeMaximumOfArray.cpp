class Solution {

public:

    static int max(int a, int b)

    {

        return a>b ? a : b;

    }

    int minimizeArrayValue(vector<int>& nums) {

        long long int sums = 0;

        int mx = 0, n = nums.size();

        for(int i=0; i<n; i++)

        {

            sums += nums[i];

            mx = max(ceil(double(sums)/(i+1)), mx);

        }

        return mx;

    }

};
