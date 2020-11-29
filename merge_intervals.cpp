#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_slot;
        merged_slot.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            
            if (merged_slot[merged_slot.size() - 1][1] >= intervals[i][0]
                && merged_slot[merged_slot.size() - 1][1] <= intervals[i][1])
                merged_slot[merged_slot.size() - 1][1] = intervals[i][1];
            
            else if (merged_slot[merged_slot.size() - 1][1] < intervals[i][0])
                merged_slot.push_back(intervals[i]);
        }
        return merged_slot;
    }
};