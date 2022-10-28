class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        vector<int> res;
        for(int i: nums)
        {
            freq[i]++;
        }
        priority_queue<vector<int>> heap;
        for(auto i: freq)
        {
            heap.push({i.second, i.first});
        }
        for(int i=1; i<=k; i++)
        {
            vector<int> top = heap.top();
            res.push_back(top[1]);
            heap.pop();
        }
        return res;
    }
};
