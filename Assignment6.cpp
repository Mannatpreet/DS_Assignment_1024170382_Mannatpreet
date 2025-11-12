#include <iostream>
#include <string>
using namespace std;

class Node{

public: 
    int data;
    Node *prev;
    Node *next;

    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class circularDoublyLinkedList{

public: 

    Node *head;

    circularDoublyLinkedList(){
        head = nullptr;
    }



    void insertAtStart(int num) {
        Node *newNode = new Node(num);

        if(head == nullptr){
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node *last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            head->prev = newNode;
            last->next = newNode;

            head = newNode;
        }
    }



    void insertAtEnd(int num){
        Node *newNode = new Node(num);

        if(head == nullptr){
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
        }else{
            Node *last = head->prev;
            newNode->prev = head->prev;
            newNode->next = head;
    
            last->next = newNode;
            head->prev = newNode;
        }
    }



    void insertAfterGivenNumber(int num, int givenNum){
        Node *newNode = new Node(num);
        Node *counter = head;
        
        if(head == nullptr){
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
        }else{
            while(counter->next != head){
                if(counter->data == givenNum){
                    break;
                }
                counter = counter->next;
            }
        
            Node *setAfterThis = counter;
            newNode->next = counter->next;
            newNode->prev = counter;

            setAfterThis->next = newNode;
            (counter->next)->prev = newNode;
        }
    }



    void deleteFromStart(){
        if(head == nullptr){
            cout << "List is empty";
        }else{
            Node *toDelete = head;

            if(head->next == head){
                head = nullptr;
                delete toDelete;
                return;
            }
            (head->prev)->next = head->next;
            (head->next)->prev = head->prev;
            head = head->next;
            delete toDelete;
        }
    }



    void deleteFromEnd(){
        if(head == nullptr){
            cout << "List is empty";
        }else{
            Node *toDelete = head->prev;

            if(head->next == head){
                head = nullptr;
                delete toDelete;
                return;
            }
            (toDelete->prev)->next = head;
            head->prev = (toDelete)->prev;
            delete toDelete;
        }
    }



    void deleteWithGivenValue(int givenNum){
        if(head == nullptr){
            cout << "List is empty";
        }else{
            Node *counter = head;

            do{
                if(counter->data = givenNum){
                    break;
                }
                counter = counter->next;
            }while(counter != head);

            Node *toDelete = counter;

            (counter->next)->prev = counter->prev;
            (counter->prev)->next = counter->next;

            delete toDelete;
        }
    }



    bool search(int key) {
    if(head == nullptr) {
        cout << "List is empty";
        return false;
    }

    Node *counter = head;
    do {
        if(counter->data == key) {
            cout << key << " found in the list\n";
            return true;
        }
        counter = counter->next;
    } while(counter != head);

    cout << key << " not found in the list\n";
    return false;
    }



    void explicitShow() {
        if(head == nullptr) {
            cout << "Empty list";
            return;
        }
        int flag = 0;
        Node *counter = head;
        do {
            if(flag == 2){
                break;
            }
            if(counter == head){
                flag++;
            }
            cout << counter->data << " -> ";
            counter = counter->next;
        } while(counter != head && flag < 2);

        cout << head->data << endl;
    }



    bool checkPalindrome() {
        if(head == nullptr) {
            cout << "Empty list can't be a palindrome\n";
            return false;
        }

        Node *left = head;
        Node *right = head->prev;

        while(left != right && left->prev != right) {
            if(left->data != right->data)
                return false;

            left = left->next;
            right = right->prev;
        }

        return true;
    }



    bool checkCircular(){
        if(head == nullptr) {
            cout << "Empty list";
            return false;
        }

        Node *counter = head->next;
        while(counter != nullptr && counter != head) {
            counter = counter->next;
        }

        if(counter == head) {
            return true; 
        } else {
            return false;
        }
    }




};

int main(){
    circularDoublyLinkedList list;

    list.insertAtStart(5);
    list.insertAtStart(7);
    list.insertAtStart(9);
    list.insertAtStart(11);
    list.insertAtStart(13);

    list.explicitShow();
    return 0;
}