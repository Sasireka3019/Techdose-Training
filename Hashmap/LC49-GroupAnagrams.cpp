class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        unordered_map <string, vector<string>> smap;
        for(string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            smap[t].push_back(s);
        }
        for(auto it : smap)
        {
            anagrams.push_back(it.second);
        }
        return anagrams;
    }
};
