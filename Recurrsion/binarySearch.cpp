#include <iostream>
using namespace std;

void binarySearch(int *arr, int key, int start, int end) {
    if (start > end) {
        cout << "Not Found" << endl;
        return;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
        cout << key << " is at position " << mid << endl;
        return;
    }

    if (arr[mid] > key) {
        binarySearch(arr, key, start, mid - 1); // Search in the left half
    } else {
        binarySearch(arr, key, mid + 1, end); // Search in the right half
    }
}
int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in sorted order: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int key;
    cout << "Enter the target value: ";
    cin >> key;

    binarySearch(arr, key, 0, n - 1);

    return 0;
}
