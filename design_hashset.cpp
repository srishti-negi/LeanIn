#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/design-hashset/

class MyHashSet {
public:
    int bucket_num;
    vector <vector <int>> buckets;
    int hash_func (int key) {
        return key % bucket_num;}
    /** Initialize your data structure here. */
    MyHashSet() {
        bucket_num = 20000;
        buckets = vector <vector <int>> (bucket_num, vector <int> {});
    }
    
    void add(int key) {
        int i = hash_func (key);
        if(find (buckets[i].begin(), buckets[i].end(), key) == buckets[i].end())
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash_func (key);
        auto idx = find (buckets[i].begin(), buckets[i].end(), key);
        if (idx != buckets[i].end())
            buckets[i].erase(idx);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hash_func (key);
        return (find (buckets[i].begin(), buckets[i].end(), key) != buckets[i].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */