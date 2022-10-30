class Solution {
public:
    int calculate(string s) {
        int sum = 0, n = s.length(), sign = 1;
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i])==1)
            {
                long long num = 0;
                while(i < n && isdigit(s[i])==1)
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                sum += (sign*num);
                i--;
            }
            else if(s[i] == '(')
            {
                st.push(make_pair(sum, sign));
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                sum = st.top().first + (st.top().second)*sum;
                st.pop();
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
        }
        return sum;
    }
};
