#include <iostream>
#include <vector>
#include <algorithm>

// refer to https://leetcode.com/problems/first-missing-positive/ for my solution on leetcode
using namespace std;

class Solution {
public:
    int firstMissingPositive (vector <int> & nums) {
        
        if (nums.size() < 1 || (nums.size() == 1 && nums[0] < 1) )
            return 1;
        
        if (nums.size() == 1) 
            if (nums[0] == 1)
                return 2;
            else
                return 1;
        
        sort(nums.begin(), nums.end());
       // cout << "a";
        
        int first_positive = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                first_positive = i;
                break;
            }          
        }
        //cout <<"\nfirst positive" <<first_positive;
        
        if ( first_positive == -1 || nums[first_positive] > 1)
            return 1;
        
        for (int j = first_positive; j < nums.size() - 1; j++) {
            if (nums[j + 1] - nums[j] > 1)
                return nums[j] + 1;
        }
        
        return nums[nums.size() - 1] + 1;
    }
};