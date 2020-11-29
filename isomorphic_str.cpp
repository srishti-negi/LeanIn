#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/isomorphic-strings/

class Solution {
public:
    
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map <char, char> map;
        unordered_set <char> mapped;
        
        for (int i = 0; i < s.length(); i++) {
            
            if(map.find(s[i]) == map.end()) {
                if (mapped.find(t[i]) != mapped.end()) {
                    return false;
                }
                map[s[i]] = t[i];
                mapped.insert(t[i]);
            }
            
            else if (map[s[i]] != t[i])
                    return false;
        }
        return true;
    }
};