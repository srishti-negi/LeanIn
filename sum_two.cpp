#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashmap;
        vector <int> sum_2;
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                sum_2 = {hashmap[target - nums[i]], i};
                break;
            }
            else
                hashmap[nums[i]] = i;     
        }
        return sum_2;
    }
};