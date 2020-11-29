#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/contest/biweekly-contest-39/problems/defuse-the-bomb/

class Solution {
public:
    int sum_next (vector <int> code, int k, int idx) {
        int sum_k = 0;
        for (int i = idx + 1; i < code.size() && k > 0; i++) {
            sum_k += code[i];
            k--;
        }
        for (int i = 0; i < k; i++) {
            sum_k += code[i];
        }
        cout << endl;
        return sum_k;
    }
    int sum_prev (vector <int> code, int k, int idx) {
        int sum_k = 0;
        for (int i = idx - 1;k < 0 && i >= 0; i--) {
            sum_k += code[i];
            k++;
        }
        for (int i = code.size() - 1; k < 0 ; i--) {
            sum_k += code[i];
            k++;
        }
        return sum_k;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        vector <int> ans;
        for (int i = 0; i < code.size(); i++) {
            if (k > 0) 
                ans.push_back (sum_next(code, k, i));
            else if (k < 0) 
                ans.push_back (sum_prev(code, k, i));
            else
                ans.push_back(0);
            cout << ans[i] << " ";
        }
        return ans;
    }
};