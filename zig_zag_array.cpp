# include <iostream>
using namespace std;

void zig_zag_array (int arr[], int len) {
    int temp;
    for (int i = 0; i < len - 1; i++) {
        if (i%2 == 0) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;}
        }
        else if (arr[i] < arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;}
    }
    for (int i = 0; i < len; i++)
    cout << arr [i] << " ";
}

int main () {
    int arr[4] = {1, 4, 3, 2};
    int len = 4;
    zig_zag_array(arr, len);
    return 0;
}