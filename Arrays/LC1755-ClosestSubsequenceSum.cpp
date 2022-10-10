class Solution {
public:
    
    void subsequenceSums(int start, int end, int total, vector<int>& nums, vector<int>& sums){
        if(start==end){
            sums.push_back(total);
            return;
        }
        subsequenceSums(start+1, end, total, nums, sums);        
        subsequenceSums(start+1, end, total + nums[start], nums, sums);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), ans = INT_MAX;
        vector<int> left, right;
        
        subsequenceSums(0, n/2+1, 0, nums, left);        
        subsequenceSums(n/2+1, n, 0, nums, right);
        
        for(int& x : left)
            ans = min(ans, abs(x - goal));
        for(int& x : right)
            ans = min(ans, abs(x - goal));
        
        sort(begin(left), end(left));        
        sort(begin(right), end(right));
        
        int l = 0, r = right.size() - 1;
        
        while(l<left.size() && r>=0){
            int s = left[l] + right[r];
            ans = min(ans, abs(s - goal));
            if(s<goal) l++;
            else if(s>goal) r--;
            else break;
        }
        
        return ans;
    }
};
