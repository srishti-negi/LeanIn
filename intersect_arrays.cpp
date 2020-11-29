#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> hashmap1;
        vector <int> intersection;
        
        for (int num: nums1)
            hashmap1[num]++;
        
        for (int num: nums2) 
            if (hashmap1[num] > 0) {
                intersection.push_back(num);
                hashmap1[num]--;
            }
                
        return intersection;
    }
};