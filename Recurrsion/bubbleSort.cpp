#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n, int i) {
    if (i > n - 2) return; // Base case: if i exceeds limit, stop recursion
    for (int j = 0; j < n - i - 1; j++) { // inner loop for comparisons
        if (arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]); // Swap if elements are out of order
        }
    }
    bubbleSort(arr, n, i + 1); // Recursive call for the next pass
}

int main() {
    int n;
    cout << "Enter Size of Array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr, n, 0); // Call the recursive bubble sort function

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
