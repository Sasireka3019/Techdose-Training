class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_cost = 0, curr_cost = 0, start = 0;
        for(int i=0; i<n; i++)
        {
            total_cost += (gas[i]-cost[i]);
            curr_cost += (gas[i]-cost[i]);
            if(curr_cost < 0)
            {
                curr_cost = 0;
                start = i+1;
            }
        }
        if(total_cost < 0)
            return -1;
        else
            return start;
    }
};
