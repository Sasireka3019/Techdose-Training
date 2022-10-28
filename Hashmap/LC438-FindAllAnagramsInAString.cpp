class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26, 0), shash(26, 0), res;
        int len = s.size(), window = p.size();
        if(len < window)
            return res;
        int left = 0, right = 0; 
        while(right<window)
        {
            phash[p[right]-'a'] += 1;
            shash[s[right]-'a'] += 1;
            right++;
        }
        right--;
        while(right < len)
        {
            if(phash == shash)
                res.push_back(left);
            shash[s[left]-'a'] -= 1;
            right++;
            if(right < len)
                shash[s[right]-'a'] += 1;
            left++;
        }
        return res;
    }
};
