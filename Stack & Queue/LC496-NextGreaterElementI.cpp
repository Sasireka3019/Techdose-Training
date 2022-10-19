class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> mp;
        vector <int> res; 
        stack <int> sj;
        for(int i : nums2)
        {
            while(sj.size() && i > sj.top())
            {
                mp[sj.top()] = i;
                sj.pop();
            }
            sj.push(i);
        }
        for(int i : nums1)
        {
            res.push_back(mp.count(i) ? mp[i] : -1);
        }
        return res;
    }
};
