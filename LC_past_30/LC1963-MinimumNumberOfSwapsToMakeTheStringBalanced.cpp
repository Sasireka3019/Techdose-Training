class Solution {
public:
    int minSwaps(string s) {
        int ans=0,cnt=0;
        for(char c:s) {
            if(c=='[') 
            {
                ++cnt;
            } 
            else 
            {
                --cnt;
                if(cnt<0) 
                {
                    cnt+=2;
                    ++ans;
                }
            }
        }
        return ans;
    }
};
