class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> sum(1000011, 0);
        int mx = INT_MIN;
        for(vector<int> i : intervals)
        {
            sum[i[0]] += 1;
            sum[i[1]+1] -= 1;
        }
        for(int i=1; i<1000011; i++)
        {
            sum[i] = sum[i-1]+sum[i];
            mx = max(sum[i], mx);
        }
        return mx;
    }
};
