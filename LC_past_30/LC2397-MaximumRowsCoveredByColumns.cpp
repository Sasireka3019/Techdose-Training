class Solution {
private:
    int ans = 0;
public:
    void select(vector<vector<int>>& mat, int cols, int r, int c, vector<bool> visited, int index)
    {
        if(cols == 0)
        {
            int count = 0;
            for(int i=0; i<r; i++)
            {
                int flag = 0;
                for(int j=0; j<c; j++)
                {
                    if(mat[i][j] == 1)
                    {
                        if(visited[j] == false)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0)
                    count++;
            }
            ans = max(ans, count);
            return;
        }
        if(index == c)
            return;
        visited[index] = true;
        select(mat, cols-1, r, c, visited, index+1);
        visited[index] = false;
        select(mat, cols, r, c, visited, index+1);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int r = mat.size(), c = mat[0].size();
        vector<bool> visited(c, false);
        select(mat, cols, r, c, visited, 0);
        return ans;
    }
};
