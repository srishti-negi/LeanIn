#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> intersection;
        for (int num1: nums1) {
            auto id = find(nums2.begin(), nums2.end(), num1);
            if (id != nums2.end()) {
                intersection.push_back(num1);
                nums2.erase(id);
        }
        }
        return intersection;
    }
};
