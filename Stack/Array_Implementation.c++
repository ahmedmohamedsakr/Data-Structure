#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1, M = 1e6 + 1, mod = 1e9 + 7, OO = 0x3f3f3f3f;

template<typename T>
class Stack {
    T a[N];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(T data) {
        if (top == N - 1) {
            cout << "Error: stack overflow.\n";
            return;
        }
        a[++top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Error: No element to pop.\n";
            return;
        }
        --top;
    }

    T Top() {
        return a[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void print() {
        if (top == -1)cout << "Stack is empty.\n";
        else {
            for (int i = top; i > -1; --i) {
                cout << a[i] << "\t";
            }
            puts("");
        }
    }
};

int main() {
    Stack<string> s;
    s.push("ahmed");
    s.push("mohamed");
    s.push("ali");
    s.print();           //{ali,mohamed,ahmed}
    cout << "top of stack = " << s.Top() << endl;    //top of stack = ali
    cout << "Stack after pop:\n";
    s.pop();
    s.print();         //{mohamed,ahmed}
    cout << "top of stack = " << s.Top() << endl;      //top of stack = mohamed
    puts(s.isEmpty() ? "Stack is empty." : "Stack is not empty.");  //Stack is not empty.
    return 0;
}
