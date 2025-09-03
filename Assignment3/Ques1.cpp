#include <iostream>
using namespace std;

struct Stack {
    int stackArr[10];
    int ptr;
};

Stack createStack() {
    Stack s;
    s.ptr = -1;
    return s;
}

bool isFull(Stack s) {
    return s.ptr == 9;
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
        cout << s.stackArr[i] << endl;
    }
    cout << endl;
}

int main() {
    Stack s = createStack();

    s = push(s, 1);
    s = push(s, 7);
    s = push(s, 67);
    s = push(s, 45);
    s = push(s, 99);
    s = push(s, 6);

    printStack(s);

    cout << "Peek: " << peek(s) << endl;
    s = pop(s);
    s = pop(s);
    s = pop(s);

    printStack(s);

    return 0;
}