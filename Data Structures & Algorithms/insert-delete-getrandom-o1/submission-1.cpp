class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numMap.count(val))
        {
            return false;
        }
        
        numMap[val] = nums.size();
        nums.push_back(val);

        return true;
    }
    
    // Example walkthrough
    // numMap [0,3,5] -> [0,1,2]
    // nums   [0,3,5]
    // Remove val 3
    bool remove(int val) {
        if (!numMap.count(val))
        {
            return false;
        }

        int valIdx = numMap[val]; // 1
        int lastNum = nums.back(); // 5

        nums[valIdx] = lastNum; // [0,3,5] -> [0,5,5]
        numMap[lastNum] = valIdx; // [0,3,5] -> [0,1,2] ->-> [0,3,5] -> [0,1,1]

        nums.pop_back(); // [0,5,5] -> [0,5]
        numMap.erase(val); // [0,3,5] -> [0,1,1] ->-> [0,5] -> [0,1]
        
        return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    unordered_map<int,int> numMap;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */