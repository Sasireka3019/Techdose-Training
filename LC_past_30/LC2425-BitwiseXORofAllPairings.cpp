class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0, n1 = 0, n2 = 0;
        for(int i : nums1)
        {    
            xor1 = xor1^i;
            n1 += 1;
        }
        for(int i : nums2)
        {
            xor2 = xor2^i;
            n2 += 1;
        }
        if(n1%2 == 0 && n2%2 == 0)
            return 0;
        else if(n1%2 == 0 && n2%2 != 0)
            return xor1;
        else if(n1%2 != 0 && n2%2 == 0)
            return xor2;
        else
            return xor1^xor2;
    }
};
