#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> occured_char;
        int longest_len = 0;
        int i= 0, j = 0, n = s.length();
        while (i < n && j < n) {
            if (occured_char.find(s[j]) == occured_char.end()) {
                occured_char.insert(s[j]);
                j++;
                longest_len = max(longest_len, j - i);
            }
            else {
                occured_char.erase(s[i++]);
            }
        }
        return longest_len;
    }
};