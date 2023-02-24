class Solution {
public:
    string lcs(string& A, string& B) {
        int n = A.size(), m = B.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i] == B[j])
                    dp[i + 1][j + 1] = dp[i][j] + A[i];
                else
                    dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        string s = lcs(str1, str2), res = "";
        int l = s.length(), i = 0, j = 0;
        for(int k=0; k<l; k++)
        {
            while(str1[i] != s[k])
            {
                res += str1[i];
                i++;
            }
            while(str2[j] != s[k])
            {
                res += str2[j];
                j++;
            }
            i++;
            j++;
            res += s[k];
        }
        return res+str1.substr(i)+str2.substr(j);
    }
};
