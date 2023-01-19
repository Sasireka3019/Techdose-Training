class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> ranges(26, -1), res;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            ranges[s[i]-'a'] = i;
        } 
        int currEnd = 0, farCanReach = 0, cnt = 0;
        for(int i=0; i<n; i++)
        {
            farCanReach = max(farCanReach, ranges[s[i]-'a']);
            if(i == farCanReach)
            {
                res.push_back(i-currEnd+1);
                currEnd = i+1;
            }
        }
        return res;
    }
};
/*
a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
8  5  7 14 15 11 13 19 22 23 20 21  

a  b  a  b  c  b  a  c  a  d  e  f  e  g  d  e  h  i  j  h  k  l  i  j
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
*/
