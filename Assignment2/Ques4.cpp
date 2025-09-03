#include <iostream>
using namespace std;

int findStringLength(char ch[]){
    int length = 0;
    for(int i=0; ch[i] != '\0'; i++){
        length++;
    }
    return length;
}

void stringCat(char ch1[], char ch2[]){
    int lengthOfFirst = 0;
    int length1 = findStringLength(ch1);
    int length2 = findStringLength(ch2);

    // cout << length1  << " . . " << length2;

    for(int i=length1, j=0; j<length2; j++, i++){
        ch1[i] = ch2[j];
    }
    cout << ch1;
}

void reverseStr(char ch[]){
    int length = findStringLength(ch);
    int s = 0;
    int e = length-1;

    while(s<e){
        char temp = ch[s];
        ch[s] = ch[e];
        ch[e] = temp;

        s++;
        e--;
    }

    cout << ch;
}

void deleteVowel(char ch[]){
    for(int i=0; ch[i]!='\0'; i++){
        if(ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u'){
            int j = i;
            for(; ch[j]!='\0'; j++){
                ch[j] = ch[j+1];
            }
            i--;
        }
    }
    cout << ch;
}

char convertToLower(char ch){
    if(ch >= 'A' && ch<= 'Z'){
        ch = ch - 'A' + 'a';
    }
    return ch;
}

void bubbleSort(char ch[]){

    int length = findStringLength(ch);
    
    for(int i=0; i<length-1; i++){

        for(int j=0; j<length-i-1; j++){
            if(convertToLower(ch[j]) > convertToLower(ch[j+1])){
                char temp = ch[j];
                ch[j] = ch[j+1];
                ch[j+1] = temp;
            }
        }

    }
    cout << ch << endl;
}

int main(){
    char ch1[100] = "Mannatpreet";
    char ch2[100] = "Singh";
    // stringCat(ch1, ch2);
    // reverseStr(ch1);

    char ch3[100] = "aAeioufuckYouBabyaeiuoA";
    // deleteVowel(ch3);
    bubbleSort(ch3);

    char ch = 'A';
    // convertToLower(ch);
    return 0;
}