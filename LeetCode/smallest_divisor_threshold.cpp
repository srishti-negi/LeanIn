#include<iostream>
#include<vector>
using namespace std;

//https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/564/week-1-november-1st-november-7th/3521/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //sort(nums.begin(), nums.end());
        int len = nums.size();
        int thresh_fact = INT_MAX;
        int max_ele = *max_element (nums.begin(), nums.end());
        int lo = 1, hi = max_ele, mid;
        double x;
        
        while (lo < hi) {
            mid = (lo + hi) / 2;
            int thresh_sum = 0;
            for (int j = 0; j < len; j++) {
                x = ceil(nums[j]/float(mid));
                thresh_sum += x;
            }
            //cout << lo << " " << hi << " " << mid << " " << thresh_sum << endl;
            if (thresh_sum > threshold) {
                 lo = mid + 1;
            }
            else {
                // thresh_fact = min (thresh_fact, mid);
                hi = mid;
            }  
        }
       
        return lo;
    }
    // (brute force)
    // for (int i = 1; i <= max_ele; i ++) {
        //     double thresh_sum = 0;
        //     for (int j = 0; j < len; j++) {
        //         x = ceil(nums[j]/float(i));
        //         //cout << x << " ";
        //         thresh_sum += x;
        //     }
        //     if (thresh_sum <= threshold) {
        //         thresh_fact = i;
        //         break;
        //     }
        //     //cout << endl;
        // }
};
