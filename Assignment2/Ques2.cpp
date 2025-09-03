#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " . ";
    }
}

int main() {
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr, 7);

    printArray(arr, 7);
    return 0;
}
