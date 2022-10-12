class Solution {
public:
    static char minim(vector<int> freq)
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i] != 0)
                return i+'a';
        }
        return 'a';
    }
    string robotWithString(string s) {
        stack <int> t;
        string p = "";
        vector<int> freq(26,0);
        for(char c : s)
        {
            freq[c-'a'] += 1;
        }
        for(char c : s)
        {
            t.push(c);
            freq[c-'a'] -= 1;
            while(t.empty() == 0 && t.top() <= minim(freq))
            {
                char ch = t.top();
                t.pop();
                p += ch;
            }
        }
        while(t.empty() == 0)
        {
            char ch = t.top();
            t.pop();
            p += ch;
        }
        return p;
    }
};
