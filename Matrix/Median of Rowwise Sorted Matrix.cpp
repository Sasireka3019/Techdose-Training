class Solution{   

public:

    int median(vector<vector<int>> &matrix, int r, int c){

        int mini = matrix[0][0], maxi = matrix[0][c-1];

        for(int i=0; i<r; i++)

        {

            mini = min(mini, matrix[i][0]);

            maxi = max(maxi, matrix[i][c-1]);

        }

        int desired = (r*c+1)/2;

        while(mini < maxi)

        {

            int mid = mini + (maxi - mini)/2;

            int place = 0;

            for(int i=0; i<r; i++)

            {

                for(int j=0; j<c; j++)

                {

                    if(matrix[i][j] <= mid)

                    place++;

                }

            }

            if(place < desired)

                mini = mid+1;

            else 

                maxi = mid;

        }

        return mini;

    }

};
