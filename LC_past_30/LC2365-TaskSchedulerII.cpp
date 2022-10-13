class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long int, long long int> smap;
        long long int days = 0, index = 0;
        for(int t : tasks)
        {
            if(smap.find(t) != smap.end() && !(days-smap[t]>=space))
                days += (space-(days-smap[t])+1);
            else
                days++;
            smap[t] = days;
            index++;
        }
        return days;
    }
};
