#include <iostream>
#include <vector>

using namespace std;

void display_vec (vector <int> arr) {
    for (int p: arr)
    cout << p;
    cout << endl;

}
void sort_012 (vector <int> arr) {
    int lo = 0, hi = arr.size() - 1;
    int mid = 0;
    int cp = 0;
    while ( mid < hi) {
        
        cout << " " << cp << " " << lo << " " << hi << endl;
        if (arr[mid] == 2) {
        swap(arr[mid], arr[hi]);
        hi--;}

        if (arr[mid] == 1) {
        mid++;}

        if (arr[mid] == 0) {
        swap(arr[lo], arr[mid]);
        lo++;}

        display_vec(arr);
    }

    
}

int main() {
    vector <int> arr = {2, 2, 1,  0, 2, 0, 1};
    sort_012(arr);
    
    return 0;
}