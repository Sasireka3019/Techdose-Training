class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> heap;
        map<char, int> freq;
        for(auto t : tasks)
            freq[t] += 1;
        for(auto it : freq)
            heap.push({it.second, it.first});
        int count = 0;
        while(!heap.empty())
        {
            int k = n+1;
            queue<pair<int, int>> temp;
            while(!heap.empty() && k > 0)
            {
                int f = heap.top().first;
                char c = heap.top().second;
                heap.pop();
                temp.push({f-1, c});
                count++;
                k--;
            }
            while(!temp.empty())
            {
                if(temp.front().first != 0)
                    heap.push(temp.front());
                temp.pop();
            }
            if(heap.empty())
                break;
            count += k;
        }
        return count;
    }
};
