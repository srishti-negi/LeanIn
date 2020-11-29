#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        
        for (int i = 0; i <= r; i++) {
             if (isalpha(s[i]) && islower(s[i])) {
                 s[i] = s[i] - 32;
             }
        }
        
        while (l < r) {
            if (!isalnum(s[l])) l++;
            if (!isalnum(s[r])) r--;
            if (isalnum(s[r]) && isalnum(s[l])) {
                cout << s[l] << " " << s[r] << endl;
                if (s[l] != s[r])
                    return false;
                l++, r--;
            }
        }
        return true;
    }
};