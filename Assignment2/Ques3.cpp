#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int length){
    int i=0;
    int counter = 1;
    int arrSum = 0;
    for(int j=0; j<length; j++, counter++){
        arrSum += arr[j];

        i += counter;
        // cout << arrSum << " . . " << i << endl;
        if(arrSum != i){
            return counter;
            break;
        }
    }
    return -1;
}

int findMissingBinary(int arr[], int length){
    int s = 0;
    int e = length - 1;
    int mid = (s+e)/2;

    while(s<=e){
        if(arr[mid] == mid+1){
            s = mid+1;
        }else{
            e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return s+1;
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 9, 10, 11};

    int ans = findMissingLinear(arr, 10);
    int ans2 = findMissingBinary(arr, 10);
    cout << ans2;
}