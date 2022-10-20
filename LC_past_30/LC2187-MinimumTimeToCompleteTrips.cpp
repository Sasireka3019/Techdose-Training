class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 100000000000001, ansTillNow = -1;
        while(left <= right)
        {
            long long int mid = left + (right-left)/2;
            long long trips = 0;
            for(int i : time)
            {
                trips += (mid/i);
            }
            if(trips >= totalTrips)
            {
                ansTillNow = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return ansTillNow;
    }
};
