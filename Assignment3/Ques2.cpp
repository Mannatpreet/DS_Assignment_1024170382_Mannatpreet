#include <iostream>
#include <string>
using namespace std;

struct Stack {
    int stackArr[50];
    int ptr;
};

Stack createStack() {
    Stack s;
    s.ptr = -1;
    return s;
}

bool isFull(Stack s) {
    return s.ptr == 49;
}

bool isEmpty(Stack s) {
    return s.ptr == -1;
}

Stack push(Stack s, int element) {
    if (!isFull(s)) {
        s.ptr++;
        s.stackArr[s.ptr] = element;
    }
    return s;
}

Stack pop(Stack s) {
    if (!isEmpty(s)) {
        s.ptr--;
    }
    return s;
}

int peek(Stack s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s.stackArr[s.ptr];
}

void printStack(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << endl;
    for (int i = s.ptr; i >= 0; i--) {
        cout << char(s.stackArr[i]) << endl;
    }
    cout << endl;
}

int main() {
    Stack storage = createStack();

    string str = "DataStructure";
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        storage = push(storage, str[i]);
        length++;
    }

    for (int j = 0; !isEmpty(storage); j++) {
        str[j] = peek(storage);
        storage = pop(storage);
    }
    str[length] = '\0';

    cout << str << endl;

    return 0;
}