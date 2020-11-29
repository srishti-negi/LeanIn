#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string, int> hashmap;
        for (int i = 0; i < list1.size(); i++) {
            hashmap[list1[i]] = i;
        }
        vector <string> min_str;
        int min_idx_sum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
               if (hashmap.find(list2[i]) != hashmap.end()) {
                   if (i + hashmap[list2[i]] < min_idx_sum) {
                       min_str = {};
                       min_idx_sum = i + hashmap[list2[i]];
                   }
                   if (i + hashmap[list2[i]] == min_idx_sum)
                       min_str.push_back(list2[i]);
                }
        }
        return min_str;
    }
};