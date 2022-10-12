class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size(), len = s.length();
        vector <int> sums(len+1);
        for(vector<int> shft : shifts)
        {
            if(shft[2] == 0)
            {
                sums[shft[0]] -= 1;
                sums[shft[1]+1] += 1;
            }
            else
            {
                sums[shft[0]] += 1;
                sums[shft[1]+1] -= 1;
            }
        }
        for(int i=1; i<=len; i++)
        {
            sums[i] += sums[i-1];
        }
        for(int i=0; i<len; i++)
        {
            int k=sums[i]%26;
            int p=(s[i]-'a'+k+26)%26;
            s[i]=char('a'+p);
        }
        return s;
    }
};
