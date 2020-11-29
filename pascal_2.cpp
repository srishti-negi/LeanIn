#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> curr_row;
        curr_row.push_back(1);
        if (rowIndex == 0)
            return curr_row;
        vector <int> prev_row = getRow(rowIndex - 1);
        for (int i = 0; i < prev_row.size() - 1; i ++) 
            curr_row.push_back(prev_row[i] + prev_row[i + 1]);
        curr_row.push_back(1);
        return curr_row;
    }
};