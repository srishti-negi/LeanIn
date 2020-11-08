#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool in_row (vector <char> row, char element, int c){
        for (int i = 0; i < row.size(); i++)
            if (row[i] == element && i != c)
                return true;
        // cout << endl << element << " r ";
        return false;
    }
    bool in_column (vector<vector<char>> board, char element, int r, int c){
        for (int i = 0; i < board.size(); i++) {
            if (board[i][c] == element && i != r)
                return true;
        }
        // cout << element << " c ";
        return false;
    }
    bool in_box (vector<vector<char>> board, char element, int r, int c) {
        
        for (int i = 3 * (r/3); i < 3 * (r/3) +3; i++){
            for (int j = 3 * (c/3); j < 3 * (c/3) + 3; j++) {
                if (board[i][j] == element && i != r && j!=c)
                    return true;
                //cout << board[i][j] << " ";
            }
        }
        //cout << element << " b " <<r<<" "<<c <<endl;
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] != '.') 
            {
                    if (in_row(board[i], board[i][j], j) || in_column(board, board[i][j], i, j) || in_box(board,                               board[i][j], i, j))
                            return false;
                    // bool r = in_box(board,board[i][j], i, j);
                    // cout << endl;
                }
        return true;
    }
};
