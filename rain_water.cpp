#include <iostream>

using namespace std;

int rain_water_1 (int arr [], int len) {
    int total_water = 0;
    int left = 0, right = 0;
    for (int i = 0; i < len - 1; i++) {
        left = arr[i], right = arr[i];
        for (int k = 0; k < i; k++)
        left = max(arr[k], left);
        for (int l = i + 1; l < len; l++)
        right = max(arr[l], right);

        int diff = min(left, right);
        cout << left << " " << right << " " << total_water << " " << (diff) << endl;
        total_water += (diff - arr[i]);
    }
    return total_water;
}

int main () {
    int arr[11] = {1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    //int arr[6] = {3, 0, 0, 2, 0, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << rain_water_1(arr, len);
    return 0;
}