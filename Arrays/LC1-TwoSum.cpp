class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
        vector <int> result;
        int index = 0;
        for(int i : nums)
        {
            if(hash.find(target-i) == hash.end())
                hash[i] = index;
            else
            {
                result.push_back(hash[target-i]);
                result.push_back(index);
            }
            index += 1;
        }
        return result;
    }
};
