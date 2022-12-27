class Solution {
public:
    int minCost(string colors, vector<int>& need) {
        int totalCost = 0, maxCost = 0, n = colors.length(), res = 0;
        for(int i=0; i<n-1; i++)
        {
            if(colors[i] == colors[i+1])
            {
                totalCost += need[i];
                maxCost = max(maxCost, need[i]);
            }
            else
            {
                if(totalCost != 0 && maxCost != 0)
                {
                    res += ((totalCost + need[i]) - max(maxCost, need[i]));
                }
                totalCost = 0;
                maxCost = 0;
            }
        } 
        if(totalCost != 0 && maxCost != 0)
        {
            res += ((totalCost + need[n-1]) - max(maxCost, need[n-1]));
        }
        return res;
    }
};
