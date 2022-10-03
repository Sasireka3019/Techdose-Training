class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefixSum = nums;
        int n = nums.size();
        for(int i=1; i<n; i++)
            prefixSum[i] = prefixSum[i-1]+nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return prefixSum[right];
        return prefixSum[right]-prefixSum[left-1];
    }
    private:
    vector<int> prefixSum;
};
