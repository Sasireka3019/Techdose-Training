class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(dfs(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string &word, int i, int j)
    {
        if(!word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        bool ret = dfs(board, s, i-1, j) || dfs(board, s, i+1,j) || dfs(board, s, i, j-1)|| dfs(board, s, i, j+1);
        board[i][j] = c;
        return ret;
    }
};
