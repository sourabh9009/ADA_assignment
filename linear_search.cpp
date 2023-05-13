#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return index where x is found
        }
    }
    return -1; // If x is not found in the array, return -1
}

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 15;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}
