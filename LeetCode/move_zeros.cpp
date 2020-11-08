#include <iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[non0] = nums[i];
                non0++;
            }
        }
        for (int i = non0; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
