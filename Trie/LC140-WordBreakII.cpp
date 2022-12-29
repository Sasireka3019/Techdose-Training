class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<string> res;
        for(auto w: wordDict)
            set.insert(w);
        solve(0, s, "", set, res);
        return res;
    }
    void solve(int index, string s, string curr, unordered_set<string> set, vector<string> &res)
    {
        int n = s.length();
        if(index == an)
        {
            curr.pop_back();
            res.push_back(curr);
        }
        string str = "";
        for(int i=index; i<n; i++)
        {
            str.push_back(s[i]);
            if(set.count(str))
            {
                solve(i+1, s, curr+str+" ", set, res);
            }
        }
    }
};
