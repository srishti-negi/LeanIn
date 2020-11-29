#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int num = 0;
        int sign = 1;
        
        while (i < s.length() && s[i] == ' ' )
            i++;
        
        if (isalpha(s[i]))
            return 0;
        
        if (s[i] == '-' && i + 1 < s.length() && isdigit(s[i + 1])) {
            sign = -1; i++;}
        if (s[i] == '+' && i + 1 < s.length() && isdigit(s[i + 1])) {
            sign = 1; i++;}
        cout << s[i] << " " << sign <<endl<< INT_MIN <<endl<< INT_MAX;
        while (i < s.length() && isdigit(s[i]) )  {
            if (num > INT_MAX / 10 || num == INT_MAX / 10 && s[i] -'0' > INT_MAX % 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            num = num * 10 + (s[i++] - '0');
        }
        return num * sign;
    }
};