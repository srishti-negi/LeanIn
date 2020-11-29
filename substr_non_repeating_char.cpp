#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/jewels-and-stones/

class Solution {
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set <char> jewels;
        int count_jewels = 0;
        for (char ch: J)
            jewels.insert(ch);
        for (char ch: S)
            if (jewels.find(ch) != jewels.end())
                count_jewels++;
        return count_jewels;
    }
};