class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> hashMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.find(val) != hashMap.end())
        {
            return false;
        }
        hashMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.find(val) == hashMap.end())
        {
            return false;
        }
        swap(nums[hashMap[val]], nums[nums.size() - 1]);
        nums.pop_back();
        hashMap[nums[hashMap[val]]] = hashMap[val];
        hashMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
