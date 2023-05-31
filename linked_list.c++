#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = nullptr;
// node *preLast = nullptr;

// display the data of each node in the linked list.
void display();

// methods for inserting a node.
void push_front(int value);
void push_back(int value);
void insert(int value, int index);

// methods for deleting a node.
void pop_front();
void pop_back();
void deleteByValue(int value);
void deleteByPosition(int index);

void Reverse();

void RecursiveReverse(node *p);

int main()
{
    push_back(4);
    push_back(25);
    insert(8, 2);
    display(); //{4,8,25}
    deleteByValue(25);
    cout << "delete 25:\n";
    display(); //{4,8}
    pop_front();
    cout << "delete beginning:\n";
    display(); //{8}
    push_front(4);
    cout << "insert 4 at beginning:\n";
    display(); //{4,8}
    push_back(25);
    cout << "insert 25 at end:\n";
    display(); //{4,8,25}
    push_back(30);
    cout << "insert 30 at end:\n";
    display(); //{4,8,25,30}
    pop_back();
    cout << "delete end:\n";
    display(); //{4,8,25}
    cout << "after reverse:\n";
    Reverse();
    display(); //{25,8,4}
    cout << "after recursive reverse:\n";
    RecursiveReverse(head);
    display(); //{4,8,25}
    return 0;
}

// notes:
// 1- To access members of a structure, use the dot operator. To access members of a structure
//  through a pointer, use the arrow operator.
// 2- delete -> only be used either for the pointers pointing to the memory allocated using new
//  operator or for a NULL pointer.

void display()
{
    node *currentNode;
    if (head == nullptr)
    {
        cout << "linked list is empty.";
    }
    else
    {
        currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
    puts("");
}

// insert node at the end of the linked list.
// time complexity: O(n).
void push_back(int value)
{
    node *newNode = new node;
    newNode->data = value;

    // if there is no node.
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }
    newNode->next = nullptr;
}

// insert node at the front of the linked list.
// time complexity: O(1).
void push_front(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// inserting node at n-th position.
// indexing: 1-based.
// assert that index is exist.
// time complexity: O(n).
void insert(int value, int index)
{
    node *newNode = new node;
    newNode->data = value;
    if (index == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node *temp = head;
        for (int idx = 0; idx < index - 2; ++idx)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// delete node from the front of the linked list.
// time complexity: O(1).
void pop_front()
{
    if (head == nullptr)
    {
        cout << "linked list is empty.\n";
    }
    else
    {
        node *firstNode = head;
        head = firstNode->next;
        delete firstNode;
    }
}

// delete node from the back of the linked list.
// time complexity: O(n).
void pop_back()
{
    node *ptr;
    if (head == nullptr)
    { // linked list is empty.
        cout << "empty linked list is empty.\n";
    }
    else if (head->next == nullptr)
    { // linked list has only one node.
        delete head;
        // delete preLast;
        head = nullptr;
    }
    else
    { // liked list has more than one node.
        ptr = head;
        // while the next of the Node after me not equal nullptr.
        while (ptr->next->next != nullptr)
        {
            ptr = ptr->next; // stop at the Node directly before the last Node.
        }
        // delete preLast->next; // last Node.

        // delete the last element from memory.
        delete ptr->next;
        ptr->next = nullptr;
    }
}

// deleting node by its value.
// time complexity: O(n).
void deleteByValue(int value)
{
    node *current = head, *previous = head;
    if (head == nullptr)
    { // empty linked list.
        cout << "linked list is empty.\n";
    }
    else
    { // more than one node.
        //(current-->next!=nullptr):To terminate the loop if I reach the end of the list and the value not found in it.
        while (current->data != value && current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        // This condition because I can exit the previous loop when I reach the end and not found the value which I search for.
        if (current->data == value)
        {
            previous->next = current->next;
            delete current;
        }
    }
}

// deleting node at n-th position.
// indexing: 1-based.
// assert that index is exist.
// time complexity: O(n).
void deleteByPosition(int index)
{
    node *temp = head;
    if (index == 1)
    {
        head = temp->next;
        delete temp;
    }
    else
    {
        // get the node before the one you want to delete.
        for (int idx = 0; idx < index - 2; idx++)
        {
            temp = temp->next;
        }
        // temp is equal to the node before the one you want to delete.
        // temp2 initialized by the deleted node.
        node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
}

void Reverse()
{
    node *previous, *current, *next;
    current = head;
    previous = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void RecursiveReverse(node *p)
{
    if (p->next == nullptr)
    {
        head = p;
        return;
    }
    RecursiveReverse(p->next);
    p->next->next = p;
    p->next = nullptr;
}

// using recursion to print the elements of the linked list.
// void recursiveDisplay(node *currentNode){
//          if(currentNode==nullptr)return;
//          cout<<currentNode->data<<" ";
//          recursiveDisplay(currentNode->next);
// }
