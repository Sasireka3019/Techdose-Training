class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        map <int, int> hm;
        vector <int> res;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            hm[nums[i]] = i;
        }
        for(vector<int> v : op)
        {
            nums[hm[v[0]]] = v[1];
            hm[v[1]] = hm[v[0]];
            hm.erase(v[0]);
        }
        res = nums;
        return res;
    }
};
