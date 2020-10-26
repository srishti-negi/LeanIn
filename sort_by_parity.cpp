#include <iostream>
#include <vector>
using namespace std;

//refer to https://leetcode.com/problems/sort-array-by-parity/submissions/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // if (A.size() <= 1)
        //     return A;
        int l = 0, r = A.size() - 1;
        while (l < r){
            if (A[l] % 2 == 1) {
                swap(A[l], A[r]);
                r--;
            }
            else 
                l++;
        }
        return A;
    }
};