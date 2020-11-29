#include <iostream>
#include <cmath>

using namespace std;
//Brute force,     Time complexity: O(n^2)
void diff_ (int arr[], int n, int diff) {
    for (int i = 0; i < n - 1; i ++)
        for (int j = i + 1; j < n ; j++){
            //cout <<j<<" " << arr[i] <<" "<<arr[j]<<endl;
            if (abs(arr[i]-arr[j]) == diff ) {
                cout << i<< ": " << arr[i] <<", " << j <<": " << arr[j] << endl;
                return;
            }}
    cout << "element not found";
}
//optimised
void diff_2 (int arr[], int n, int diff) {
    int i = 0;
    int j = 1;
    while(i < n - 1) {
            if (arr[j] - arr[i] < diff)
                j++;
            else if (arr[j]-arr[i] == diff ) {
                cout << i<< ": " << arr[i] <<", " << j <<": " << arr[j] << endl;
                return;
            } 
            else{
                i++;j = i + 1;
            }
        cout << i << " " << j << endl;
            
        }
    cout << "element not found";
}

bool findPair(int arr[], int size, int n)  
{  
    // Initialize positions of two elements  
    int i = 0;  
    int j = 1;  
  
    // Search for a pair  
    while (i < size)  
    {  
        if (i != j && arr[j] - arr[i] == n)  
        {  
            cout << "Pair Found: (" << arr[i] << 
                        ", " << arr[j] << ")";  
            return true;  
        }  
        else if (arr[j]-arr[i] < n)  
            j++;  
        else
            i++;  
        cout << i << " " << j << endl;
    }  
  
    cout << "No such pair";  
    return false;  
}  
int main () {
    int arr1[] = {2, 3, 5, 6, 20, 50, 82, 84}, n1 = 78;  //{5, 20, 3, 2, 50, 80}
    int arr2[] = {90, 70, 20, 80, 50}, n2 = 45;
    cout << findPair(arr1, 6, n1);
    diff_2(arr1, 6, n1);
    diff_2(arr2, 5, n2);
    return 0;
}