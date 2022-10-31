class Solution {

public:

    int calculate(string s) {

        stack<int> st;

        char sign = '+';

        int n = s.length(), i = 0, sum = 0, p = 1;

        while(i < n)

        {

            long num = 0;

            if(isdigit(s[i]))

            {

                while(i<n && isdigit(s[i]))

                {

                    num = num*10 + (s[i]-'0');

                    i++;

                }

                num = p*num;

                if(sign == '*')

                {

                    int x = st.top();

                    st.pop();

                    st.push(x*num);

                }

                else if(sign == '/')

                {

                    int x = st.top();

                    st.pop();

                    st.push(x/num);

                }

                else

                {

                    st.push(num);

                }

                i--;

            }

            else if(s[i] != '-')

                p = 1;

            else if(s[i] == '-')

                p = -1;

            if(s[i] != ' ')

                sign = s[i];

            i++;

        }

        while(!st.empty())

        {

            sum += st.top();

            st.pop();

        }

        return sum;

    }

};
