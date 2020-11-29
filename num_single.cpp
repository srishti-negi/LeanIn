#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set <int> hashset;
        for (int num: nums) {
            if (hashset.find(num) == hashset.end())
                hashset.insert(num);
            else
                hashset.erase(num);
        }
        for (int num: nums)
            if (hashset.count(num) > 0)
                return num;
        return -1;
    }
};