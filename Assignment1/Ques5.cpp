#include <iostream>
using namespace std;

void sumRowAndColumn(int arr[][3], int rows, int columns){
    int rowSum = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            rowSum += arr[i][j];
        }
        cout << "For row no " << i+1 << " Sum is: " << rowSum << endl;
        rowSum = 0;
    }

    cout << endl;

    int colSum = 0;
    for(int i=0; i<columns; i++){
        for(int j=0; j<rows; j++){
            colSum += arr[j][i];
        }
        cout << "For col no " << i+1 << " Sum is: " << colSum << endl;
        colSum = 0;
    }
}

int main(){
    
    int dArray[3][3] = {{0, 1, 2}, {1, 0, 2}, {0, 0, 1}};
    sumRowAndColumn(dArray, 3, 3);

    return 0;
}