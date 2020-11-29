#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), l = needle.length();
        for (int i = 0; i <= n - l; i++) {
            bool needle_found = true;
            cout << haystack[i] << " ";
            for (int j = 0; j < l; j++) {
                if (haystack[i + j] != needle[j]) {
                    needle_found = false;
                    break;
                }
            }
            if (needle_found) 
                return i;
        }
        return -1;
    }
};