class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int result = 0, sum = 0, tsum = 0;
        string gar = "MPG";
        int arr[3] = {0};
        for(int i=0; i<n-1; i++)
        {
            tsum += travel[i];
        }
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cnt = 0;
                for(char ch : garbage[j])
                {
                    if(ch == gar[i])
                    {
                        cnt += 1;
                        sum += 1;
                    }
                }
                if(cnt > 0)
                {
                    result += cnt;
                    arr[i] = j;
                }
            }
        }
        result = sum + (tsum*3);
        //cout<<sum<<" "<<tsum<<" "<<result<<" ";
        for(int i=0; i<3; i++)
        {
            int j=arr[i];
            //cout<<j<<" ";
            for(; j<n-1; j++)
            {
                result -= travel[j];
            }
        }
        return result;
    }
};
