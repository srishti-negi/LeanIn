#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int mountain(vector <int> A, int idx) {
        int r_depth = 0, l_depth = 0, i;
        int max_till_now = A[idx];
        for (i = idx + 1; i < A.size() ; i++) {
            if (max_till_now > A[i]) {
                r_depth ++; max_till_now = A[i];}
            else
                break;
        }
        max_till_now = A[idx];
        for (i = idx - 1; i >= 0; i--) {
            if (max_till_now > A[i]) {
                l_depth ++; max_till_now = A[i];}
            else
                break;
        }
        if (l_depth == 0 || r_depth == 0)
            return 0;
        return l_depth + r_depth + 1;
    }
    
    int longestMountain(vector<int>& A) {
        int height = 0;
        for (int i = 0; i < A.size(); i++) {
            height = max (height, mountain (A, i));
        }
        return height;
    }
};