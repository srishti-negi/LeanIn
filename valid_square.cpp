#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/valid-square/

class Solution {
public:
    int sq_length (vector <int> p1, vector <int> p2) {
            return pow((p1[0] - p2[0]), 2) +  pow((p1[1] - p2[1]), 2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector <int> lengths;
        
        lengths.push_back(sq_length (p1, p2));
        lengths.push_back(sq_length (p2, p3));
        lengths.push_back(sq_length (p3, p4));
        lengths.push_back(sq_length (p4, p1));
        lengths.push_back(sq_length (p1, p3));
        lengths.push_back(sq_length (p2, p4));
        
        sort (lengths.begin(), lengths.end());
        
        int h = lengths[0], s = lengths[lengths.size() - 1];
        
        int fh = 0, fs =0;
        
        for(int l: lengths) {
            if (l == h)
                fh++;
            else if (l == s)
                fs++;
        }
        return ( (fh == 4 && fs == 2 ) || (fh == 2 && fs == 4) );
    }
};