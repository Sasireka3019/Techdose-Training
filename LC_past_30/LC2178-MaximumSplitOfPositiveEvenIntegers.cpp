class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> sol;
        if(finalSum%2 == 0)
        {
            long long curSum = 0, i = 2;
            while((curSum+i) <= finalSum)
            {
                sol.push_back(i);
                curSum += i;
                i += 2;
            }
            int size = sol.size();
            sol[size-1] += (finalSum-curSum);
        }
        return sol;
    }
};
