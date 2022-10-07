class Solution {
public:
    static int binarySearch(int low, int high, vector<int> weights, int days, int sol)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2, i = 1, sum = 0, n = weights.size(), flag = 0;
            for(int w : weights)
            {
                sum += w;
                if(sum > mid)
                {
                    sum = w;
                    i++;
                }
            }
            if(i <= days)
            {
                sol = mid;
                return binarySearch(low, mid-1, weights, days, sol);
            }
            else
            {
                return binarySearch(mid+1, high, weights, days, sol);
            }
        }
        return sol;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0), low = *max_element(weights.begin(), weights.end()), sol = 0;       
        return binarySearch(low, high, weights, days, sol);
    }
};
