class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector <int> pipes(n+1);
        for(int i = 0; i <= n; i++)
        {
            if(ranges[i] != 0)
            {
                int left = max(0, i-ranges[i]);
                pipes[left] = max(pipes[left], i+ranges[i]);
            }
        }
        int currEnd = 0, farCanReach = 0, cnt = 0;
        for(int i=0; i<n+1 && currEnd<n; currEnd = farCanReach)
        {
            cnt++;
            while(i < n+1 && i <= currEnd)
                farCanReach = max(farCanReach, pipes[i++]);
            if(currEnd == farCanReach)
                return -1;
        }
        return cnt;
    }
};
