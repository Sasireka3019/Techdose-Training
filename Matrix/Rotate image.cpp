class Solution {

public:

    void rotate(vector<vector<int>>& matrix) {

        //transpose

        int n = matrix.size();

        for(int i=0; i<n; i++)

        {

            for(int j=i; j<n; j++)

            {

                swap(matrix[i][j], matrix[j][i]);

            }

        }

        //swapping columns using 2 pointers

        for(int i=0; i<n; i++)

        {

            int left = 0, right = n-1;

            while(left < right)

            {

                swap(matrix[i][left], matrix[i][right]);

                left++;

                right--;

            }

        }

    }

};
