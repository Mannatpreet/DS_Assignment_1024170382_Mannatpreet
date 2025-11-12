#include <iostream>
#include <string>
using namespace std;

class Node {

public: 
    int data;
    Node *next;
    
    Node(int num){
        data = num;
        next = nullptr;
    }
};



class linkedList {
    
private: 
    Node *head;
    
public:



    linkedList(){
        head = nullptr;
    }

    

    void insertAtStart() {
        int num;
        cout << "Enter the value to insert at start: ";
        cin >> num;

        Node *newNode = new Node(num);

        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    


    void insertAtEnd() {
        int num;
        cout << "Enter the value to insert at end: ";
        cin >> num;

        Node *newNode = new Node(num);
        
        if(head == NULL){
            head = newNode;
        }else{
            Node *counter = head;
            
            while(counter->next != NULL){
                counter = counter->next;
            }
            
            counter->next = newNode;
        }
    }
    


    void insertAtGivenPosition() {

        int num, positionData;
        cout << "Enter the value to insert and the element after which to insert: ";
        cin >> num, positionData;

        Node *newNode = new Node(num);
        
        if(head == NULL){
            head = newNode;
        }else{
            Node *counter = head;
            
            while(counter->next != nullptr){
                
                if(counter->data == positionData){
                    break;    
                }
                
                counter = counter->next;
            }
            
            if(counter->next == nullptr){
                cout << "Given element not found; insertion unsuccessful." << endl;
            }else{
                newNode->next = counter->next;
                counter->next = newNode;                
            }
        }
    }
    


    void deleteFromStart(){
        if(head == nullptr){
            cout << "Empty list";
        }else{
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
    


    void deleteFromEnd(){
        if(head == nullptr){
            cout << "Empty list";
        }
        else if(head->next == nullptr){ 
            delete head;
            head = nullptr;
        }
        else{
            Node *counter = head;

            while((counter->next)->next != NULL){
                counter = counter->next;
            }
            
            Node *toDelete = counter->next;
            counter->next = nullptr;
            delete toDelete;
        }
    }
    


    void deleteAtGivenPosition() {

        int key;
        cout << "Enter the element to delete: ";
        cin >> key;

        if(head == nullptr) {
            cout << "Empty list" << endl;
            return;
        }
        
        if(head->data == key) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
    
        Node *counter = head;
        while(counter->next != nullptr && (counter->next)->data != key) {
            counter = counter->next;
        }
    
        if(counter->next == nullptr) {
            cout << "Element not found after full transerval" << endl;
            return;
        }
    
        Node *toDelete = counter->next;
        counter->next = (counter->next)->next; // (counter->next)->next will the nullptr only if the key is found at last node.
        delete toDelete;
    }




    void deleteValue(int val) {
        if (head == nullptr) {
            cout << "Nothing to delete";
            return;
        }

        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* counter = head;
        while (counter->next != nullptr && counter->next->data != val) {
            counter = counter->next;
        }

        if (counter->next == nullptr) {
            cout << "Value not found.";
        } else {
            Node* toDelete = counter->next;
            counter->next = counter->next->next;
            delete toDelete;
        }
    } // Second trail which is independent




    int searchFromHead(int key){
        if(head == nullptr){
            cout << "Empty list" << endl;
        }else{
            Node *counter = head;
            int flag = 0;
            int position = 1;
            while(counter != nullptr){
                if(counter->data == key){
                    flag = 1;
                    break;
                }

                counter = counter->next;
                position++;
            }

            if(flag == 1){
                cout << "Key found at position " << position << " if head is considered 1.";
                return position;
            }else{
                cout << "Key not found.";
                return flag;
            }
            
        }
    }


    
    void explicitShow(){
        if(head == nullptr){
            cout << "Empty list.";
            return; 
        }else{
            Node *counter = head;

            while(counter != nullptr){
                cout << counter->data << " -> ";
                counter = counter->next;
            }

            cout << "NULL";
        }
    }



    int noOfOccurencesAndDelete(int key) {
        int count = 0;

        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            count++;
        }

        Node* counter = head;
        while (counter != nullptr && counter->next != nullptr) {
            if (counter->next->data == key) {
                Node* toDelete = counter->next;
                counter->next = counter->next->next;
                delete toDelete;
                count++;
            } else {
                counter = counter->next;
            }
        }

        return count;
    }



    void findTheMiddle(){
        Node *slowPtr = head;
        Node *fastPtr = head;

        while(fastPtr != nullptr && fastPtr->next != nullptr){
            fastPtr = (fastPtr->next)->next;
            slowPtr = slowPtr->next;
        }

        cout << slowPtr->data << " is the middle element";
    }



    void reverseLinkedList() {
        if(head == nullptr) {
            cout << "List empty, nothing to reverse" << endl;
            return;
        }

        Node *prev = nullptr; 
        Node *curr = head;    
        Node *next = nullptr; 

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    linkedList list;

    while(true){
        char ch;
        cout << "Do you want to perform an operation on linked list? : ";
        cin >> ch;
        if(ch == 'n'){
            break;
        }else{
            int n;
            cout << "Enter the option number to execute: ";
            cout << endl << "1: Insert at start" << endl;
            cout << "2: Insert at end" << endl;
            cout << "3: Insert after specific number" << endl;
            cout << "4: Delete from start" << endl;
            cout << "5: Delete from end" << endl;
            cout << "6: Delete any specific number" << endl;
            cout << "7: *** Display the linked list" << endl;
            cout << "8: Reverse" << endl << endl;
            cin >> n;
             
            switch(n){
                case 1: list.insertAtStart();
                        break;

                case 2: list.insertAtEnd();
                        break;                
                        
                case 3: list.insertAtGivenPosition();
                        break;                
                        
                case 4: list.deleteFromStart();
                        break;                
                        
                case 5: list.deleteFromEnd();
                        break;                
                        
                case 6: list.deleteAtGivenPosition();
                        break;

                case 7: list.explicitShow();
                        break;

                case 8: list.reverseLinkedList();
                        break;
            }

        }
        
    }
    
    // list.explicitShow();
    // cout << endl;

    return 0;
}