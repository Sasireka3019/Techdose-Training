class Solution {
public:
    int reverse(long long n, bool skip) {
    long long res = 0;
    for (n = skip ? n / 10 : n; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}
    vector<long long> kthPalindrome(vector<int>& queries, int intlength) {
        vector <long long> res;
        long long int base = pow(10, ((intlength+1)/2)-1);
        long long int end = base*10;
        long long int multiply = pow(10, intlength/2);
        for(int curr : queries)
        {
            if(curr+base-1 >= end)
                res.push_back(-1);
            else
                res.push_back((base+curr-1)*multiply+reverse(base+curr-1, intlength%2));
        }
        return res;
    }
};
