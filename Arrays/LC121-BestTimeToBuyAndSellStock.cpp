class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int left = 0, right = 1, n = prices.size();
        while(right < n)
        {
            if(prices[left] < prices[right])
            {
                int curr = prices[right]-prices[left];
                if(curr > max)
                    max = curr;
            }
            else
            {
                left = right;
            }
            right++;
        }
        return max;
    }
};
