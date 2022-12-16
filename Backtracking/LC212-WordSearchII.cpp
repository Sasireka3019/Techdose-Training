class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {NULL};
        string word = "";
        bool found = false;
    };
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void helper(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& res, vector<vector<bool>>& visited) {
        if(!root->children[board[i][j] - 'a']) {
            return;
        }
        visited[i][j] = true;
        root = root->children[board[i][j] - 'a'];
        if(root->word.size() > 0 && !root->found) {
            root->found = true;
            res.push_back(root->word);
        }
        for(auto d : dir) {
            int m = i + d[0];
            int n = j + d[1];
            if(m >= 0 && m < board.size() && n >= 0 && n < board[0].size() && !visited[m][n]) {
                helper(board, m, n, root, res, visited);
            }
        }
        visited[i][j] = false;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty()) {
            return res;
        }
        TrieNode* root = new TrieNode();
        for(auto w : words) {
            TrieNode* p = root;
            for(auto c : w) {
                if(p->children[c - 'a'] == NULL) {
                    p->children[c - 'a'] = new TrieNode();
                }
                p = p->children[c - 'a'];
            }
            p->word = w;
        }
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                helper(board, i, j, root, res, visited);
            }
        }
        return res;
    }
};
