#include <iostream>
using namespace std;

int askForOption(){
    int optionNo;
    cout << "Option 1 -> Display the array" << endl;
    cout << "Option 2 -> Insert into array" << endl;
    cout << "Option 3 -> Delete from array" << endl;
    cout << "Option 4 -> Search in array" << endl << endl;

    cin >> optionNo;
    return optionNo;
}

void createArray(int arr[], int length){
    for(int i=0; i<length; i++){
        cout << "Enter element no. " << i+1 << " : ";
        cin >> arr[i];
    }
}

void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
        cout << arr[i] << " . ";
    }
}

int insertIntoArray(int arr[], int length){
    int element, index;
    cout << endl << "Enter the element and index of new element to insert: " << endl;
    cin >> element >> index;
    
    for(int i=length; i>= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return ++length;
}

int deleteFromArray(int arr[], int length){
    // int index;
    // cout << "Enter the index of element to delete: " << endl;
    // cin >> index;
    
    // for(int i=index; i< length; i++){
    //     arr[i] = arr[i+1];
    // }
    
    int element;
    cout << endl << "Enter the element to delete: " << endl;
    cin >> element;
    
    for(int i=0; i<length; i++){
        if(arr[i] == element){
            for(int j=i; j<length; j++){
                arr[j] = arr[j+1];
            }
             break;
        }
    }
    return --length;
}

void linearSearch(int arr[], int length){
    int key;
    int flag = 0;
    int index = -1;
    
    cout << endl << "Enter the key to search for in array: ";
    cin >> key;
    
    for(int i=0; i<length; i++){
        if(arr[i] == key){
            flag = 1;
            index = i;
            break;
        }
    }

    if(flag){
        cout << key << " is present at index " << index << endl;
    }else{
        cout << key << " is not present." << endl;
    }
}

int main(){

    cout << "Create an array -> " << endl;
    int noOfElement;
    cout << "Enter the number of elements: ";
    cin >> noOfElement;
    int arr[100];
    createArray(arr, noOfElement);
    
    int flag = 1;
    int optionSelected;
    
    while(flag){
        char resp;
        cout << "Want to perform an operation -> y/n?: ";
        cin >> resp;
        
        if(resp == 'y'){
            cout << "Enter the option no. to execute process: " << endl << endl;
            optionSelected = askForOption();
            switch(optionSelected){
                case 1: printArray(arr, noOfElement);
                        break;
        
                case 2: noOfElement = insertIntoArray(arr, noOfElement);
                        printArray(arr, noOfElement);
                        break;
        
                case 3: noOfElement = deleteFromArray(arr, noOfElement);
                        printArray(arr, noOfElement);
                        break;
                
                case 4: linearSearch(arr, noOfElement);
                        break;
            }
        }
        else{
            flag = 0;
        }
    }
    return 0;
}