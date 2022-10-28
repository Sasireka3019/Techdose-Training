class Solution {
public:
    static int count(int m, int n, int mid)
    {
        int cnt = 0;
        for(int i=1; i<=m; i++)
        {
            cnt += min(mid/i, n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int mini = 1, maxi = m*n, solu;
        while(mini <= maxi)
        {
            int mid = mini + (maxi - mini)/2;
            if(count(m, n, mid) < k)
                mini = mid+1;
            else 
                maxi = mid-1, solu = mid;
        }
        return solu;
    }
};
