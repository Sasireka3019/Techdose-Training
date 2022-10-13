class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = "I"+pattern;
        int n = pattern.length(), mx = 0;
        string result = "";
        int prev = 0;
        for(int i=0; i<n; i++)
        {
            if(i!=(n-1) && pattern[i] == 'I' && pattern[i+1] == 'D')
            {
                    int count = 0;
                    int j = i+1;
                    while(j<n && pattern[j] == 'D')
                    {
                        j++;
                        count++;
                    }
                    result += ((mx+count+1)+'0');
                    prev = (mx+count+1);
            }
            else if(pattern[i] == 'I')
            {
                result += ((1+mx)+'0');
                prev = mx+1;
            }
            else if(pattern[i] == 'D')
            {
                result += ((prev-1)+'0');
                prev -= 1;
            }
            mx = max(prev, mx);
        }
        return result;
    }
};
