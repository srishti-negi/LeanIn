#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/rotate-array/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector <int> last_k;
        k = k % len;
        for (int i = len - k; i < len; i++)
            last_k.push_back(nums[i]);
        for (int i = len - k - 1; i >= 0; i--) 
            nums[i + k] = nums[i];
        for (int i = 0; i < k; i++)
            nums[i] = last_k[i];
        
        
    }
};
