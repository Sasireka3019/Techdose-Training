 class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            int res = 0;
            stack <int> index;
            height.push_back(0);
            int n = height.size();
            for(int i=0; i<n; i++)
            {
                while(!index.empty() && height[index.top()] >= height[i])
                {
                    int h = height[index.top()];
                    index.pop();
                    int ind = index.empty() ? -1: index.top();
                    if(h*(i-ind-1) > res)
                        res = h*(i-ind-1);
                }
                index.push(i);
            }
            return res;
        }
    };
 
