#include <iostream>
#include <stdlib.h> 

using namespace std;

int equilibrium_idx1 (int arr [], int len) {   // BUGGY
    int li = 0, ri = len - 1;
    int sum_l = arr[li], sum_r = arr[ri];
    while (ri - li > 0) {
        cout << li <<" " << sum_l << " " << ri << " " << sum_r << endl ;
        if(sum_l <= sum_r) {
            li++;
            sum_l += arr[li];
        }
        if (sum_l > sum_r) {
            ri--;
            sum_r += arr[ri];
        }
        if (sum_l == sum_r && li >= ri) {
            return li;
        }
    }
    return -1;
}

int equilibrium_idx2 (int arr [], int len) {  // BUGGY
    int li = 0, ri = len - 1;
    int sum_l = arr[li], sum_r = arr[ri];
    int ls = sum_l, rs = sum_r;
    while (ri - li > 0) {
        cout << li <<" " << sum_l << " " << ri << " " << sum_r << endl ;
        ls += arr[li + 1];
        rs += arr[ri - 1];
        if (sum_r - ls > sum_l - rs) {
            ri --;
            sum_r += arr[ri];
        }
        else if (sum_r - ls < sum_l - rs) {
            li ++;
            sum_l += arr[li];
        }
        else if (sum_l == sum_r)
            return ri;
    }
    return -1;
}

int equilibrium_idx (int arr [], int len) {
    int sum_arr = 0, sum_l = 0, sum_r = 0;
    for (int i = 0; i < len; i++) {
        sum_arr += arr[i];
    }
    sum_r = sum_arr;
    for (int i = 0; i < len; i++) {
        sum_r -= arr[i];
        cout << sum_l << " " << sum_r << " " << sum_arr << "\n";
        if (sum_l == sum_r)
            return i;
        sum_l += arr[i];
    }
    return -1;
}

int main () {
    int arr[7] = {-7, 1, 5, 2, -4, 3, 0};
    int len = sizeof(arr)/sizeof(arr[0]); 
    cout << equilibrium_idx(arr, len);
    return 0;
}