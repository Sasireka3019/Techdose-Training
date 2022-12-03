class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        int n = candidates.size();
        solve(candidates, temp, target, 0, n);
        return res;
    }
    void solve(vector<int> &nums, vector<int> &temp, int remain, int start, int n)
    {
        if(remain == 0)
            res.push_back(temp);
        else if(remain < 0)
            return;
        else
        {
            for(int i=start; i<n; i++)
            {
                temp.push_back(nums[i]);
                solve(nums, temp, remain-nums[i], i, n);
                temp.pop_back();
            }
        }
    }
};
