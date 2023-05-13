#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted subarray
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = { 64, 25, 12, 22, 11 };
    selectionSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
