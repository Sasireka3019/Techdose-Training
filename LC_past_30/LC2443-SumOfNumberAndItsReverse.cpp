class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        int n = num/2;
        while(n <= num)
        {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            int rev = stoi(s);
            if(n+rev == num)
                return true;
            n++;
        }
        return false;
    }
};
