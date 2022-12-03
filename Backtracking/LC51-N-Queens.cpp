class Solution {
public:
    vector<vector<string>> result;
    bool isValid(vector<string> board, int row, int col)
    {
        for(int r=row; r>=0; r--)
        {
            if(board[r][col] == 'Q')
                return false;
        }
        for(int r=row, c=col; r>=0 && c>=0; r--,c--)
        {
            if(board[r][c] == 'Q')
                return false;
        }
        for(int r=row, c=col; r>=0 && c<board.size(); r--,c++)
        {
            if(board[r][c] == 'Q')
                return false;
        }
        return true;
    }
    void dfs(vector<string> &board, int row)
    {
        int n = board.size();
        if(row == n)
        {
            result.push_back(board);
            return;
        }
        for(int i=0; i<n; i++)
        {
            if(isValid(board, row, i))
            {
                board[row][i] = 'Q';
                dfs(board, row+1);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return result;
    }
};
