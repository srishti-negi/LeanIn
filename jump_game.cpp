#include <iostream>
#include <climits>
#include <vector>
#include <unordered_set>

using namespace std;

//https://leetcode.com/problems/jump-game-iii/

class Solution {
    unordered_set <int> visited;
public:
    bool canReach(vector<int>& arr, int start) {
        cout << start;
        if (start >= arr.size() || start < 0 || visited.count(start))
            return false;
        if (arr[start] == 0)
            return true;
        visited.insert(start);
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};
int main() {
    Solution s;
    vector <int> arr = {3,0,2,1,2};
    int start = 2;
    cout << s.canReach( arr, start);
    return 0;
}