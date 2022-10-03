class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), mini = INT_MAX;
        long long int sum = 0;
        deque <pair<long long, long long>> dq;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(sum >= k)
                mini = min(mini, i+1);
            while(!dq.empty() && dq.back().first >= sum)
                dq.pop_back();
            dq.push_back(make_pair(sum, i));
            pair<int, int> curr = make_pair(INT_MIN, INT_MIN);
            while(!dq.empty() && sum-dq.front().first >= k)
            {
                curr = dq.front();
                dq.pop_front();
            }
            if(curr.first != INT_MIN)
                mini = min(mini, i-curr.second);
        }
        if(mini == INT_MAX)
            mini = -1;
        return mini;
    }
};
