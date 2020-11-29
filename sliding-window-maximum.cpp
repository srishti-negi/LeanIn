#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> max_elements;
        deque <int> max_idx;
        int n = nums.size(), i;
        
        for ( i = 0; i < n; i++) {
            
            while (!max_idx.empty() && nums[i] >= nums[max_idx.back()])
                max_idx.pop_back();
            
            max_idx.push_back(i);
            
            if(i >= k - 1) 
                max_elements.push_back(nums[max_idx.front()]);
            if(max_idx.front() <= i - k + 1) 
                max_idx.pop_front();
        }
        return max_elements;
    }
};