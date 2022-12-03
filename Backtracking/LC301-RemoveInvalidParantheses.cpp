class Solution {
public:
    vector<string> res;
    unordered_map<string, int> mp;
    int countVal(string s)
    {
        stack<char> st;
        for(char c : s)
        {
            if(c == '(')
               st.push('(');
            else if(c == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
        }
        return st.size();
    }
    void solve(string s, int remove)
    {
        if(mp[s] != 0)
            return;
        mp[s] += 1;
        if(remove == 0)
        {
            if(countVal(s) == 0)
                res.push_back(s);
            return;
        }
        for(int i=0; i<s.length(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            solve(left+right, remove-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s, countVal(s));
        return res;
    }
};
