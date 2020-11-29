#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
    unordered_set<int> hashset;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool s = (hashset.find(val) == hashset.end());
        if (s)
        hashset.insert(val);
        return s;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool s = (hashset.find(val) != hashset.end());
        if (s)
            hashset.erase(val);
        return s;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int n = hashset.size();
        if (n == 0)
            return -1;
        int r = rand();
        r = r % n;
        auto itr = hashset.begin();
        for (; itr != hashset.end() && r > 0; ++itr) {
            r--;
        }
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */