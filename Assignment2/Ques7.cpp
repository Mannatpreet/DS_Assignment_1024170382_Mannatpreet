#include <iostream>
using namespace std;

int findInversions(int arr[], int length) {
    int count = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr2[4] = {4, 3, 2, 1};
    int ans = findInversions(arr2, 4);
    cout << ans;

    return 0;
}