#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
    unordered_map <int, string> rows;
public:
    int kthGrammar(int N, int K) {
        if (N == 1)
            return 0;
        
        if (K > pow(2, N - 1) / 2) 
            return 1 - kthGrammar(N-1, K - pow(2, N - 1) / 2);
        
        return kthGrammar(N-1, K);
    }
};