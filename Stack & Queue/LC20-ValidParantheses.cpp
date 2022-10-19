class Solution {
public:
    bool isValid(string s) {
        stack<char> js;
        for(char ch: s)
        {
            if(ch=='(' || ch=='[' || ch=='{')
            {
                js.push(ch);
            }
            else
            {
                if(!js.empty())
                {
                    char popped = js.top();
                    js.pop();
                    if((popped == '(' && ch == ')') || (popped == '[' && ch == ']') || (popped == '{' && ch == '}'))
                       continue;
                    else
                       return false;
                }
                else
                    return false;
            }
        }
        if(js.empty())
            return true;
        else
            return false;
    }
};
