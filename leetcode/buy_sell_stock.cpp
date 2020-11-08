#include <iostream>
#include <vector>

using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int i = 0;
        int profit = 0;
        int min_till_now = prices[0], max_till_now = prices[0];
        
        while(i < len - 1) {
            
            while (i < len - 1 && prices[i] >= prices[i + 1] )
                i++;
             min_till_now = prices[i];
            
            while (i < len - 1 && prices[i] <= prices[i + 1])
                i++;
             max_till_now = prices[i];
            
            profit += max_till_now - min_till_now;
           
        }
       return profit;
    }
};
