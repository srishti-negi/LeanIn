#include <iostream>

using namespace std;

//refer to https://leetcode.com/problems/fibonacci-number/submissions/

class Solution {
public:
    int fib(int N) {
        int f0 = 0, f1 = 1;
        if (N == 0)
            return f0;
        if (N == 1)
            return f1;
        int fn;
        for (int i = 0; i < N - 1; i++) {
            fn = f0 + f1;
            f0 = f1;
            f1 = fn;
        }
        return fn;
        
    }
};