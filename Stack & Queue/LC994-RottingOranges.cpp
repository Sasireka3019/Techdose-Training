class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int, int>> q;
        vector <int> dir = {-1,0,1,0,-1};
        int res = -1, fresh = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j] == 1)
                    fresh += 1;
            }
        }
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                pair <int, int> curr = q.front();
                q.pop();
                for(int i=0; i<4; i++)
                {
                    int x = curr.first + dir[i], y = curr.second + dir[i+1];
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
            res++;
        }
        if(fresh > 0)
            return -1;
        if(res == -1)
            return 0;
        return res;
    }
};
