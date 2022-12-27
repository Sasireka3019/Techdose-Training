class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> heap;
        map<char, int> mp;
        for(char c : s)
            mp[c] += 1;
        for(auto it : mp)
            heap.push({it.second, it.first});
        string res = "";
        int n = 2;
        while(!heap.empty())
        {
            int k = n;
            queue<pair<int, char>> temp;
            while(!heap.empty() && k > 0)
            {
                int f = heap.top().first;
                char c = heap.top().second;
                res += c;
                heap.pop();
                temp.push({f-1, c});
                k--;
            }
            while(!temp.empty())
            {
                if(temp.front().first != 0)
                    heap.push(temp.front());
                temp.pop();
            }
            if(heap.size() == 1 && heap.top().first > 1)
                return "";
            
        }
        return res;
    }
};
