class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int index = 0, t = costs.size();
        int n = t/2, minCost = 0;
        vector <int> refund(t);
        for(auto i : costs)
        {
            refund[index++] = i[1]-i[0];
            minCost += i[0];
        }
        sort(refund.begin(), refund.end());
        for(int i=0; i<n; i++)
            minCost += refund[i];
        return minCost;
    }
};

