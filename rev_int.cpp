#include <iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int rev_num = 0, r;
        while (x != 0) {
            r = x % 10;
            if (rev_num > INT_MAX/10 || rev_num < INT_MIN/10)
                return 0;
            rev_num = rev_num * 10 + r;
            x /= 10;
        }
        return rev_num;
    }
};
