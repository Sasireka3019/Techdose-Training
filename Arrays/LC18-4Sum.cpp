class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if (n < 4) 
        {
		    return result;
	    }
        for(int i=0; i<n-3; i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<n-2; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int left = j+1, right = n-1;
                while(left < right)
                {
                    long long l = nums[left], r = nums[right], f = nums[i], s = nums[j];
                    if(l+r+f+s == target)
                    {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[left]);
                        t.push_back(nums[right]);
                        result.push_back(t);
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1])
                            left++;
                        while(left < right && nums[right] == nums[right+1])
                            right--;
                    }
                    else if(l+r+f+s > target)
                    {
                        right--;
                    }
                    else if(l+r+f+s < target)
                    {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
