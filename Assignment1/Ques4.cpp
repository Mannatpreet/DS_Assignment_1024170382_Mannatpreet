#include <iostream>
using namespace std;

void print2DArray(int arr[][3], int rows, int columns){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            cout << arr[i][j] << " . ";
        }
        cout << endl;
    }
}

void transpose(int arr[][3], int rows, int columns){

    for(int i=0; i<rows; i++){
        for(int j=i; j<columns; j++){
            if(i != j){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp; 
            }
        }
    }
}

void multiply(int arr[][3], int arr2[][3], int ans[][3], int rows, int columns){

    int storeHouse = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            for(int k=0; k<columns; k++){
                storeHouse += arr[i][k] * arr2[k][j];
            }
            ans[i][j] = storeHouse;
            storeHouse = 0;
        }
    }
}

int main(){

    int dArray[3][3] = {{0, 1, 2}, {1, 0, 2}, {0, 0, 1}};
    // transpose(dArray, 3, 3);
    // print2DArray(dArray, 3, 3);
    
    int resultant[3][3];
    multiply(dArray, dArray, resultant, 3, 3);
    print2DArray(resultant, 3, 3);

    return 0;
}