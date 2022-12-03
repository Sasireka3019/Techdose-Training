class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
        solve(col, diag, anti_diag, 0, n);
        return count;
    }
    void solve(vector<bool> &col, vector<bool> &diag, vector<bool> &anti_diag, int row, int n)
    {
        if(row == n)
        {
            count += 1;
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(!col[i] && !diag[row+i] && !anti_diag[row-i+n-1])
            {
                col[i] = diag[row+i] = anti_diag[row-i+n-1] = true;
                solve(col, diag, anti_diag, row+1, n);
                col[i] = diag[row+i] = anti_diag[row-i+n-1] = false;
            }
        }
    }
};
