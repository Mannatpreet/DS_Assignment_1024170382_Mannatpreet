#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Stack2Q {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if(q1.empty()) return;
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    int top() {
        if(q1.empty()) return -1;
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q2.push(ans);
        swap(q1, q2);
        return ans;
    }

    bool empty() {
        return q1.empty();
    }
};

class Stack1Q {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        while(n > 1) {
            q.push(q.front());
            q.pop();
            n--;
        }
    }

    void pop() {
        if(!q.empty()) q.pop();
    }

    int top() {
        if(q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    string s = "aabc";
    queue<char> q;
    int freq[26] = {0};

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);

        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if(q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
