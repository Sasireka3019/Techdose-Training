class Solution {
public:
    string frequencySort(string s) {
        priority_queue <pair<int,char>> heap;
        string res = "";
        map <char, int> mp;
        for(char c: s)
            mp[c] += 1;
        for(auto it : mp)
        {
            heap.push({it.second, it.first});
        }
        while(!heap.empty())
        {
            int n = heap.top().first;
            char c = heap.top().second;
            for(int i=0; i<n; i++)
                res += c;
            heap.pop();
        }
        return res;
    }
};
