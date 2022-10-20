class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> heap;
        int mod = 1000000007;
        long long int res = 1;
        for(int i : nums)
        {
            heap.push(i);
        }
        for(int i=0; i<k; i++)
        {
            int n = heap.top();
            heap.pop();
            heap.push(n+1);
        }
        while(heap.size() > 0)
        {
            int n = heap.top()%mod;
            heap.pop();
            res = (res*n)%mod;
        }
        return res;
    }
};
