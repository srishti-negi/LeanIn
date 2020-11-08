#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry_over = 0;
        digits.insert(digits.begin(), 0);
        int idx = digits.size() - 1;
        digits[idx] += 1;      
        carry_over = digits[idx] / 10;
        digits[idx] %= 10;    
        idx--;
        
        // if (digits.size() == 1 && carry_over > 0)
        //     digits.insert(digits.begin(), carry_over);
        
        while(carry_over > 0 && idx >= 0) {
            cout << "loop";
            digits[idx] += carry_over;
            if (carry_over == 0 || digits[idx] < 10)
                break; 
            if (digits[idx] >= 10) {
                carry_over = digits[idx] / 10;
                digits[idx] %= 10;
            } 
            
            
            idx--;
        }
        if (digits[0] == 0)
            digits.erase(digits.begin());
            //digits[0] += carry_over;
            // int n = digits[0];
            //cout << n;
            // if (digits[0] >= 10) {
            //     digits[0] %= 10;
            //     while (n >= 10) {
            //         digits.insert(digits.begin(), n/10 + n % 10);
            //         n /= 10;
            //     }
            // }
        
        return digits;
    }
};
