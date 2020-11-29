#include <iostream>

using namespace std;

void subarry_sum_idx (int arr [], int sum_to_find) {
    int curr_sum = 0, si = 0, ci = 0;
    while(curr_sum != sum_to_find && ci < sizeof(arr[0])) {
        curr_sum += arr[ci];
        if (curr_sum < sum_to_find) {
            ci ++;
        }
        else if (curr_sum > sum_to_find) {
            si ++;
            ci = si;
            curr_sum = 0;
        }
        else if (curr_sum == sum_to_find) {
            cout << "Sum found between indices " << si << ", " << ci;
            return;
        }
    }
    cout << "sum not found";
}

int main() {
    //int arr[6] = {2, 4, 20, 1, 10, 5};
    int arr[6] = {2, 4, 20, 1, 10, 5}, sum_to_find = 25;
    subarry_sum_idx(arr, sum_to_find);
    return 0;
}