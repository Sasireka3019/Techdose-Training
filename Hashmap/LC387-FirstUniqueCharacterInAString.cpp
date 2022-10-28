class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26] = {0};
        for(char ch : s)
        {
            alpha[ch-'a'] += 1;
        }
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            if(alpha[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
