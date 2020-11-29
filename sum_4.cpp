#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int sum_count = 0;
        vector <int> pair_sumab;
        unordered_map <int, int> pair_sumbc;
        
        for(int a: A)
            for(int b: B)
                pair_sumab.push_back(a + b);
        
        for(int c: C)
            for (int d: D)
                pair_sumbc[c + d]++;
        
        for(int ab: pair_sumab)
            if (pair_sumbc.count(-1 * ab))
                sum_count += pair_sumbc[-1 * ab];
                
        return sum_count;
    }
};