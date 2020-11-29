#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/climbing-stairs/

class Solution {
    unordered_map <int, int> count_ways;
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        
        if(count_ways.count(n))
            return count_ways[n];
        
        count_ways[n] = climbStairs(n - 1) + climbStairs(n - 2); 
        
        return count_ways[n];
    }
};