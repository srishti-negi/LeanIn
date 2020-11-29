#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() < 1) return prefix;
        for (int i = 0; i < strs[0].length(); i++) {
            for (auto str: strs) {
                if (str[i] != strs[0][i])
                    return prefix;
            }
             prefix += strs[0][i];
        }
        return prefix;
    }
};