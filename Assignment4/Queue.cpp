#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Queue {
public:
    int queue[100];
    int front = -1;
    int back = -1;

    void enQ(int val) {
        if (isFull()) {
            cout << "Queue already full" << endl;
            return;
        } else {
            if(front == -1 && back == -1){
                front++;
                back++;
                queue[back] = val; 
            }else{
                back++;
                queue[back] = val;   
            }
        }
    }

    int dQ() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return -1;
        }else{
            if(front == back){
                int toReturn = queue[front];
                front = -1;
                back = -1;
                return toReturn;
            }else{
                int toReturn = queue[front];
                front++;
                return toReturn;
            }
        }
    }

    bool isEmpty() {
        return (front == -1 && back == -1);
    }

    bool isFull() {
        return (back == 99);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return;
        }
        for (int i = front; i <= back; i++) {
            cout << queue[i] << " -- ";
        }
        cout << endl << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return -1;
        }
        return queue[front];
    }
};

class Cqueue {
public:
    int queue[100];
    int front = -1;
    int back = -1;
    int size = 100;

    void enQ(int val) {
        if (isFull()) {
            cout << "Queue already full" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            back = 0;
            queue[back] = val;
        } else {
            back = (back + 1) % size;
            queue[back] = val;
        }
    }

    int dQ() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return -1;
        }

        int toReturn = queue[front];

        if (front == back) {
            front = -1;
            back = -1;
        } else {
            front = (front + 1) % size;
        }

        return toReturn;
    }

    bool isEmpty() {
        return (front == -1 && back == -1);
    }

    bool isFull() {
        return ((back + 1) % size == front);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << queue[i] << endl;
            if (i == back) break;
            i = (i + 1) % size;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue already empty" << endl;
            return -1;
        }
        return queue[front];
    }
};



int main(){
    Queue Langar;
    
    Langar.enQ(1);
    Langar.enQ(2);
    Langar.enQ(3);
    Langar.enQ(4);
    Langar.enQ(5);
    Langar.enQ(6);
    Langar.enQ(7);
    
    Langar.display();
    
    Queue subLangar;
    
    int total = Langar.back - Langar.front + 1;
    int half = total / 2;
    
    for(int i = 0; i < half; i++){
        subLangar.enQ(Langar.dQ());
    }
    
    Queue finalLangar;
    
    while(!subLangar.isEmpty() && !Langar.isEmpty()){
        finalLangar.enQ(subLangar.dQ());
        finalLangar.enQ(Langar.dQ());
    }
    
    
    while(!subLangar.isEmpty()){
        finalLangar.enQ(subLangar.dQ());
    }
    
    while(!Langar.isEmpty()){
        finalLangar.enQ(Langar.dQ());
    }
    
    finalLangar.display();

    return 0;
}