class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        int n = s.length();
        vector<string> bucket(n+1, "");
        map <char, int> hmap;
        for(char ch : s)
            hmap[ch] += 1;
        for(auto it : hmap)
        {
            int t = it.second;
            char c = it.first;
            for(int i=0; i<t; i++)
                bucket[t] += c;
        }
        for(int i=n; i>=0; i--)
        {
            res += bucket[i];
        }
        return res;
    }
};
