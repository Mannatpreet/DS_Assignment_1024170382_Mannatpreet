#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = (s+e) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int main() {
    int arr[7] = {2, 4, 6, 8, 10, 12, 14};
    int key = 45;

    int result = binarySearch(arr, 10, key);
    if (result != -1)
        cout << "Element is present and at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
