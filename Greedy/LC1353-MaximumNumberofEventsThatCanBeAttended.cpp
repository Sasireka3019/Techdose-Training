class Solution {
public:
    static const bool comparator(vector<int> &A, vector<int> &B)
    {
        if(A[0] != B[0])
            return A[0] < B[0];
        return A[1] < B[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comparator);
        int n = events.size(), ans = 0, i = 0;
        multiset<int> s;
        for(int d = 1; d < 100001; d++)
        {
            while(!s.empty() && *(s.begin()) < d)
                s.erase(s.begin());
            while(i < n && events[i][0] == d)
            {
                s.insert(events[i][1]);
                i++;
            }
            if(s.size() > 0)
            {
                ans++;
                s.erase(s.begin());
            }
        }
        return ans;
    }
};
