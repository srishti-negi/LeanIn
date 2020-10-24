#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display_vec (vector <int> arr) {
    for (int p: arr)
    cout << p;
    cout << endl;

}
void find_diff (vector <int> arr, int diff) {
    sort(arr.begin(), arr.end());
    int lo = 0, hi = 1;

    while (lo < hi) {
        if (arr[hi] - arr[lo] > diff)
            lo++;
        else if (arr[hi] - arr[lo] < diff)
            hi++;
        else if (hi != lo) {
            cout << arr[lo] << " " << arr[hi];
            return;}
    }
    cout << "not found";
    
}

int main() {
    vector <int> arr {5, 20, 3, 2, 50, 80}; int diff = 78;
    find_diff(arr, diff);
    return 0;
}