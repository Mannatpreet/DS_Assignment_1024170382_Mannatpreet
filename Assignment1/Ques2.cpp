#include <iostream>
using namespace std;

int deleteDuplicates(int arr[], int length){
        for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(arr[i] == arr[j]){
                for(int k=j; k<length; k++){
                    arr[k] = arr[k+1];
                }
                length--;
                j--;
            }
        }
    }
    return length;
}

void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
        cout << arr[i] << " . ";
    }
}

int main(){

    int arr[10] = {1, 2, 2, 3, 3, 3, 3, 3, 0, 10};
    int updatesLength = deleteDuplicates(arr, 10);
    printArray(arr, updatesLength);
    return 0;
}