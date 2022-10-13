class Solution {
public:
    bool sameOrder(string start, string target)
    {
        string first = "", second = "";
        for(char c : start)
        {
            if(c != '_')
                first += c;
        }
        for(char c : target)
        {
            if(c != '_')
                second += c;
        }
        return first == second;
    }
    bool canChange(string start, string target) {
        if(!sameOrder(start, target))
            return false;
        vector<int>left1, right1, left2, right2;
        int n = start.length();
        for(int i=0; i<n; i++)
        {
            if(start[i] == 'L')
                left1.push_back(i);
            else if(start[i] == 'R')
                right1.push_back(i);
            if(target[i] == 'L')
                left2.push_back(i);
            else if(target[i] == 'R')
                right2.push_back(i);
        }
        int l = left1.size(), r = right1.size();
        for(int i=0; i<l; i++)
        {
            if(left1[i] < left2[i])
                return false;
        }
        for(int i=0; i<r; i++)
        {
            if(right1[i] > right2[i])
                return false;
        }
        return true;
    }
};
