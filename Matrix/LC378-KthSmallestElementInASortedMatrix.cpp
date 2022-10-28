class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int mini = matrix[0][0], maxi = matrix[0][n-1];
        for(int i=0; i<m; i++)
        {
            mini = min(mini, matrix[i][0]);
            maxi = max(maxi, matrix[i][n-1]);
        }
        while(mini < maxi)
        {
            int place = 0;
            int mid  = mini+(maxi-mini)/2;
            for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				place += pos;
			}
            if(place < k)
                mini = mid+1;
            else
                maxi = mid;
        }
        return maxi;
    }
};
