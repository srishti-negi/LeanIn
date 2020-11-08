#include <iostream>
#include vector>

using namespace std;

//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // if (target < 0) {
        //     for (int i = 0; i < nums.size(); i++)
        //         nums[i] *= -1;
        //     target *= -1;
        // }
        vector <int> nums2 = nums;
        sort(nums.begin(), nums.end());
        int lo = 0; 
        int hi = nums.size() - 1;
        
        while (lo < hi) {
            if (nums[lo] + nums[hi] < target) {
                lo++;
            }
            else if (nums[lo] + nums[hi] > target) {
                hi--;
            }
            else if (nums[lo] + nums[hi] == target)
               break; 
            cout << nums[lo] << " " << nums[hi] << endl;
        }
        
        auto l = find(nums2.begin(), nums2.end(), nums[lo]);
        int ll = l - nums2.begin();
        
        
        auto h = find(nums2.begin(), nums2.end(), nums[hi]);
        
        if (nums[lo] == nums[hi])
             h = find(nums2.begin() + ll + 1, nums2.end(), nums[hi]);
        
        int hh = h - nums2.begin();
        return {ll,hh};
    }
};
