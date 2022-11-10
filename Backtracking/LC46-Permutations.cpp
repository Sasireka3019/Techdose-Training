class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector <int> path;
        vector <bool> visited(nums.size(), false);
        dfs(nums, path, visited);
        return res;
    }
    void dfs(vector<int> nums, vector<int> path, vector<bool> visited)
    {
        if(nums.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(visited[i] == false)
            {
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, path, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};
