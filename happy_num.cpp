#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/happy-number/

class Solution {
public:
    int sum_square(int n) {
        int sum_sq = 0;
        while (n > 0) {
            sum_sq += pow(n % 10, 2);
            n /= 10;
        }
        return sum_sq;
    }
    
    bool isHappy(int n) {
       unordered_set <int> not_happy;
       while (true) {
           if (n == 1)
               return true;
           if (not_happy.find(n) != not_happy.end())
               return false;
           not_happy.insert(n);
           n = sum_square(n);
           }
       }
};