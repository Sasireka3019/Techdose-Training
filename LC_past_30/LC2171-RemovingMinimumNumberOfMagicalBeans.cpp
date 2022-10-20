class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long res = LLONG_MAX;
        long long sum = accumulate(beans.begin(), beans.end(), 0LL), n = beans.size();
        sort(beans.begin(), beans.end());
        for(int i=0; i<n; i++)
        {
            res = min(res, sum-(n-i)*beans[i]);
        }
        return res;
    }
};
