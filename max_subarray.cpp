#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int max_subarray(vector <int> arr) {
    int max_till_end = 0, max_so_far = INT_MIN;
    for(int num: arr) {
        max_till_end += num;
        if (max_till_end > max_so_far)
            max_so_far = max_till_end;
        cout << max_so_far << " " << max_till_end << "\n";
        
        if (max_till_end < 0)
            max_till_end = 0;
        cout << max_so_far << " " << max_till_end << "\n";
    }
    return max_so_far;
}
int max_subarray_sp(vector <int> arr, int sp) {
    int max_till_end = 0, max_so_far = 0;
    for(int i = sp; i < arr.size(); i++) {
        max_till_end += arr[i];
        if (max_till_end > max_so_far)
            max_so_far = max_till_end;
        if (max_till_end < 0)
            max_till_end = 0;
    }
    for(int i = 0; i < sp; i++) {
        max_till_end += arr[i];
        if (max_till_end > max_so_far)
            max_so_far = max_till_end;
        if (max_till_end < 0)
            max_till_end = 0;
    }
    return max_so_far;
}

int max_circular_subarray(vector <int> arr) {
    int sp = 0, max_arr = 0, sum_arr;
    for (int i = 0; i < arr.size(); i ++) {
        sp = i;
        sum_arr = max_subarray_sp(arr, sp);
        if (sum_arr > max_arr) 
            max_arr = sum_arr;
    }
    return max_arr;
}

// Optimized
int max_circular_subarray2(vector <int> arr) {
    int sum_arr = 0, max_kadane = 0, max_kadane_negative;
    max_kadane = max_subarray(arr);
    for (int i = 0; i < arr.size(); i ++) {
        sum_arr += arr[i];
        arr[i] = -arr[i];
    }
    max_kadane_negative = max_subarray(arr);
    return max(max_kadane, sum_arr + max_kadane_negative);
}
int main() {
    vector<int> ar = {-1, 40, -14, 7, 6, 5, -4, -1};
    vector<int> arr = {-10, -14, -4, -1};
    cout << max_subarray(arr);
    return 0;
}