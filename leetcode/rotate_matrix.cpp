#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        for (int i = 0; i < r; i++)
            for (int j = i; j < c; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
                //cout << matrix[i][j] << " ";
            }
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][c-j-1];
                matrix[i][c-j-1] = temp;
                //cout << matrix[i][j] << " ";
            }
        //cout << r << " " << c;
        
    }
};
