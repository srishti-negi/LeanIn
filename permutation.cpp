#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <vector<int>> permutations;
        sort (nums.begin(), nums.end());
        permutations.push_back(nums);
        while (next_permutation (nums.begin(), nums.end()))
            permutations.push_back(nums);
        return permutations;
    }
};