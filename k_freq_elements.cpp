#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;
        
        unordered_map <int, int> freq;
        unordered_map <int, vector <int>> rev_freq;
        vector <int> most_freq;
        
        for (int num: nums)
            freq[num]++;
        
        for (auto i: freq)  
            rev_freq[i.second].push_back(i.first);
           
        for(int i = nums.size(); i >= 0 && k > 0; i--) {
            if (rev_freq.count(i)) {
                for(int n: rev_freq[i]) {
                    most_freq.push_back(n);
                    k--;
                }
            }
        }
        return most_freq;
    }

};