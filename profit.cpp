#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        int len = prices.size();
        int p1, p2 = 0;
        int profit = 0;
        while(p1 < len) {
            
            while (prices[p2] >= prices[p1] && p2 < len)
                p2++; 

            cout << p1 << " " << p2 << " " << profit << endl;
            if (p1 == p2)
                p1++;
            
            else {
                profit += prices[--p2] - prices[p1];
                p1 = p2 + 1;
                } 

            p2 = p1;
            cout << "aaaa";
                
        }
        cout << "Hey";
       return profit;
    }
};
void display (vector <int> nums) {
    for (int n: nums)
    cout << n << " ";
    cout << endl;
}
void moveZeroes(vector<int>& nums) {
    int lastNonZeroFoundAt = 0;
    // If the current element is not 0, then we need to
    // append it just in front of last non 0 element we found. 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
        cout << nums[i] << ": ";
        display(nums);
    }
    cout << endl;
 	// After we have finished processing new elements,
 	// all the non-zero elements are already at beginning of array.
 	// We just need to fill remaining array with 0's.
    for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
        nums[i] = 0;
        display(nums);
    }
}

int main() {
    Solution s1;
    vector <int> arr = {1,2,3,4,2,0};
    moveZeroes(arr);
    display(arr);
}