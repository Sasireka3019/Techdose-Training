class NumberContainers {
public:
    map <int, int> mp;
    map<int, set<int>> smap;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp.find(index) != mp.end())
        {
            smap[mp[index]].erase(index);
        }
        smap[number].insert(index);
        mp[index] = number;
    }
    
    int find(int number) {
        auto it = smap.find(number);
        if(it == smap.end() || it->second.empty())
            return -1;
        return *(it->second).begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
