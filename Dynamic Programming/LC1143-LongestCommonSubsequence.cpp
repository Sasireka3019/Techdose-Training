class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        int lcs[len1+1][len2+1], max;
        for(int i = 0; i < len1+1; i++)
        {
            for(int j = 0; j < len2+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    lcs[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1])
                {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else
                {
                    int top = lcs[i-1][j];
                    int left = lcs[i][j-1];
                    if(top > left)
                        max = top;
                    else
                        max = left;
                    lcs[i][j] = max;
                }
            }
        }
        return lcs[len1][len2];
    }
};
