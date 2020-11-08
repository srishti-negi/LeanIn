#include <iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        for (i = 0; i < s.length(); i++) {
            int freq = 1;
            for (int j = 0; j <s.length(); j++){
                if (s[j] == s[i] && i != j)
                {
                    freq ++;
                    break;
                } 
            }
            if (freq == 1)
                return i;
            }
        return -1;
    }
};
