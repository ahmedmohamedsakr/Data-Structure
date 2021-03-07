//notes:
//1- To access members of a structure, use the dot operator. To access members of a structure
// through a pointer, use the arrow operator.
//2- delete -> only be used either for the pointers pointing to the memory allocated using new
// operator or for a NULL pointer.
#include<bits/stdc++.h>

using namespace std;
struct node {
    int data;
    node *next;
};

node *head = nullptr;
node *preLast = nullptr;

void insertNode(int value);

void display();

void deleteNode(int value);

void insertBeginning(int value);

void deleteBeginning();

void deleteEnd();

int main() {
    insertNode(4);
    insertNode(8);
    insertNode(25);
    display();                    //{4,8,25}
    deleteNode(25);
    cout << "delete 25:\n";
    display();                    //{4,8}
    deleteBeginning();
    cout << "delete beginning:\n";
    display();                    //{8}
    insertBeginning(4);
    cout << "insert 4 at beginning:\n";
    display();                   //{4,8}
    insertNode(25);
    cout << "insert 25 at end:\n";
    display();                  //{4,8,25}
    insertNode(30);
    cout << "insert 30 at end:\n";
    display();                 //{4,8,25,30}
    deleteEnd();
    cout << "delete end:\n";
    display();                //{4,8,25}
    return 0;
}

//insert node from the end of the linked list at time complexity: O(1).
void insertNode(int value) {
    node *newNode;
    newNode = new node;
    newNode->data = value;
    if (head == nullptr) {                //if there is no node.
        head = newNode;
        preLast = head;
    } else {
        //This condition to check if there is more than one node to start moving preLast pointer.
        if (preLast->next != nullptr)preLast = preLast->next;
        preLast->next = newNode;
    }
    newNode->next = nullptr;
}

//insert node from the end of the linked list at time complexity: O(n).
//void insertNode(int value) {
//    node *newNode, *last;
//    newNode = new node;
//    newNode->data = value;
//    if (head == nullptr) {                 //if there is no node.
//        head = newNode;
//    } else {
//        last = head;
//        while (last->next != nullptr) {
//            last = last->next;
//        }
//        last->next = newNode;
//    }
//    newNode->next = nullptr;
//}
void display() {
    node *currentNode;
    if (head == nullptr) {
        cout << "linked list is empty.";
    } else {
        currentNode = head;
        while (currentNode != nullptr) {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
    puts("");
}

void deleteNode(int value) {
    node *current = head, *previous = head;
    if (head == nullptr) {                    //empty linked list.
        cout << "linked list is empty.\n";
    } else {                               //more than one node.
        //(current-->next!=nullptr):To terminate the loop if I reach the end of the list and the value not found in it.
        while (current->data != value && current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        //This condition because I can exit the previous loop when I reach the end and not found the value which I searched for.
        if (current->data == value) {
            previous->next = current->next;
            delete current;
        }
    }
}

void insertBeginning(int value) {
    node *newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteBeginning() {
    if (head == nullptr) {
        cout << "linked list is empty.\n";
    } else {
        node *firstNode = head;
        head = firstNode->next;
        delete firstNode;
    }
}

void deleteEnd() {
    node *ptr;
    if (head == nullptr) {     //linked list is empty.
        cout << "empty linked list is empty.\n";
    } else if (head->next == nullptr) {  //linked list has only one node.
        delete head;
        delete preLast;
        head = nullptr;
    } else {        //liked list has more than one node.
        ptr = head;
        //while the next of the Node after me not equal nullptr.
        while (ptr->next->next != nullptr) {
            ptr = ptr->next;  //stop at the Node directly before the last Node.
        }
        delete preLast->next; //last Node.
        ptr->next = nullptr;
    }
}
