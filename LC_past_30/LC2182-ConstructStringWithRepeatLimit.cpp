class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue <pair<char, int>> heap;
        string answer = "";
        unordered_map <char, int> mp;
        for(char c : s)
        {
            mp[c] += 1;
        }
        for(auto element : mp)
        {
            heap.push({element.first, element.second});
        }
        while(!heap.empty())
        {
            char c = heap.top().first;
            int freq = heap.top().second, proceed = repeatLimit;
            heap.pop();
            if(freq < repeatLimit)
                proceed = freq;
            for(int i=0; i<proceed; i++)
                answer += c;
            if(freq > repeatLimit)
            {
                if(!heap.empty())
                {
                    char c2 = heap.top().first;
                    int freq2 = heap.top().second;
                    answer += c2;
                    heap.pop();
                    if(freq2 > 1)
                    heap.push({c2, freq2-1});
                }
                else
                return answer;
                heap.push({c,freq-repeatLimit});
            }
        }
        return answer;
    }
};
