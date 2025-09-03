#include <iostream>
using namespace std;

int findNoOfUnique(int arr[], int length){

    int noOfUnique = 0;
    for(int i=0; i<length; i++){
        int j = 0;
        for(; j<i; j++){
            if(arr[i] == arr[j]){
                break;
            }
        }
        
        if(i == j){
            noOfUnique++;
        }
    }

    return noOfUnique;
}

int main(){
    int arr[10] = {1, 2, 5, 5, 5, 5, 5, 7, 0, -1};
    int ans2 = findNoOfUnique(arr, 10);
    cout << "The number of unique elements are -> " << ans2;

    return 0;
}