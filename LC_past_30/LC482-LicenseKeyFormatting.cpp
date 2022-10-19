class Solution {
public:
    string licenseKeyFormatting(string st, int k) {
        string res = "", s = "";
        int cnt = 0;
        for(char c : st)
        {
            if(c != '-')
                s += c;
        }
        reverse(s.begin(), s.end());
        for(char c : s)
        {
            if(cnt == k)
            {
                res += '-';
                cnt = 0;
            }
            res += toupper(c);
            cnt += 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
