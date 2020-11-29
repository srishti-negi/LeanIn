#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> anagrams;
        vector <vector <string>> grouped_anagrams;
        
        for (string str: strs) {
            string key = str; 
            sort(key.begin(), key.end());
            anagrams[key].push_back(str);
        }
        
        for (auto str: anagrams) {
            grouped_anagrams.push_back(str.second);
        }
        
        return grouped_anagrams;
    }
};