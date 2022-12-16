class Solution {
public:
    bool solved = false;
    void backtrack(vector<vector<char>> &board, int row, int col, vector<vector<int>> &rowcheck, vector<vector<int>> &colcheck, vector<vector<int>> &boxcheck)
    {
        if(solved)
            return;
        if(board[row][col] == '.')
        {
            for(int i=1; i<10; i++)
            {
                //Check if we can use this number
                if(rowcheck[row][i] == 0 && colcheck[col][i] == 0 && boxcheck[(row/3)*3+(col/3)][i] == 0)
                {
                    int idx = (row / 3 ) * 3 + col / 3;
                    rowcheck[row][i]++;
                    colcheck[col][i]++;
                    boxcheck[idx][i]++;
                    board[row][col] = char(i+'0');
                    //Moving to next cell
                    if ((col == 8) && (row == 8)) 
                        solved = true;
                    if(col == 8)
                        backtrack(board, row+1, 0, rowcheck, colcheck, boxcheck);
                    else
                        backtrack(board, row, col+1, rowcheck, colcheck, boxcheck);
                    //backtracking
                    if(!solved)
                    {
                        int idx = (row / 3 ) * 3 + col / 3;
                        rowcheck[row][i]--;
                        colcheck[col][i]--;
                        boxcheck[idx][i]--;
                        board[row][col] = '.';
                    }
                }
            }
        }
        else
        {
            //Moving to next cell
            if ((col == 8) && (row == 8)) 
                solved = true;
            else if(col == 8)
                backtrack(board, row+1, 0, rowcheck, colcheck, boxcheck);
            else
                backtrack(board, row, col+1, rowcheck, colcheck, boxcheck);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowcheck(9, vector<int>(10, 0));
        vector<vector<int>> colcheck(9, vector<int>(10, 0));
        vector<vector<int>> boxcheck(9, vector<int>(10, 0));
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                int d = board[i][j]-'0';
                if(d>=1 && d<=9)
                {
                    int idx = (i / 3 ) * 3 + j / 3;
                    rowcheck[i][d]++;
                    colcheck[j][d]++;
                    boxcheck[idx][d]++;
                }
            }
        }
        backtrack(board, 0, 0, rowcheck, colcheck, boxcheck);
    }
};
