#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        string decoded = "";
        int i = 0, n= 0;
        string repeated = "";
        
        while (i < s.length()) {
            
        for (; i < s.length() && isalpha(s[i]) ; i++)
            decoded += s[i];
        
        for (; i < s.length() && isdigit(s[i]) ; i++)
            n = n*10 + s[i] - '0';
        
        int si = ++i;
        int c_s = 1, c_e = 0;
        
        for (; i < s.length() && c_s != c_e; i++) 
            if (s[i] == '[') 
                c_s++;
            else if (s[i] == ']')
                c_e++;
        if (i - 1 - si > 0)
        repeated = decodeString(s.substr(si, i - 1 - si));
                
        for (int j = 0; j < n; j++) 
            decoded += repeated;
        n = 0; repeated = "";
        } 
        return decoded;  
    }
};