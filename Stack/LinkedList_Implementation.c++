#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Stack {
    struct node {
        T data;
        node *next;
    };
    node *top;

public:
    Stack() {
        top = nullptr;
    }

    void push(T data) {
        node *newNode = new node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        node *temp = top;
        if (top == nullptr)return;
        top = top->next;
        delete temp;
    }

    T Top() {
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void print() {
        node *temp = top;
        if (temp == nullptr)cout << "Stack is Empty.";
        else {
            while (temp != nullptr) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        puts("");
    }
};

int main() {
    Stack<double> s;
    s.push(5.0);
    s.push(6.6);
    s.push(4.8);
    s.print();           //{4.8,6.6,5.0}
    cout << "top of stack = " << s.Top() << endl;    //top of stack = 4.8
    cout << "Stack after pop:\n";
    s.pop();
    s.print();         //{6.6,5}
    cout << "top of stack = " << s.Top() << endl;      //top of stack = 6.6
    puts(s.isEmpty() ? "Stack is empty." : "Stack is not empty.");  //Stack is not empty.
    return 0;
}
