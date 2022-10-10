class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> part;
        part.push_back(1);
        res.push_back(part);
        for(int i=1; i<numRows; i++)
        {
            vector<int> part;
            part.push_back(1);
            for(int j=1; j<i; j++)
            {
                    part.push_back(res[i-1][j-1]+res[i-1][j]);
            }
            part.push_back(1);
            res.push_back(part);
        }
        return res;
    }
};
