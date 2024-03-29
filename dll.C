#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = prev = nullptr;  
    }
};

class Deque {
public:
    Node* head;
    Node* tail;
    int Size;

    Deque() {
        head = tail = nullptr;
        Size = 0;
    }

    void insertNode(int val, int index) {
        Node* newnode = new Node(val);
        if (index == 0) {
            newnode->next = head;
            if (head)
                head->prev = newnode;
            head = newnode;
            if (tail == nullptr)
                tail = newnode;
        } else if (index == Size) {
            newnode->prev = tail;
            if (tail)
                tail->next = newnode;
            tail = newnode;
            if (head == nullptr)
                head = newnode;
        } else {
            Node* temp = head;
            for (int i = 1; i < index && temp->next != nullptr; ++i)
                temp = temp->next;
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next = newnode;
            if (newnode->next)
                newnode->next->prev = newnode;
        }
        Size++;
    }

    void insertFront(int data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        Size++;
    }

    void deleteFront() {
        if (head == nullptr) {
            cout << "Underflow" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        Size--;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    // Inserting elements into deque
    dq.insertFront(122);
    dq.insertFront(2);
    dq.insertFront(2);
    dq.insertFront(2);
    dq.insertNode(3, 2);
    dq.insertNode(4, 1);
    dq.insertNode(5, 1);

    // Printing deque elements
    cout << "Deque elements: ";
    dq.print();

    // Deleting front element
    dq.deleteFront();
    cout << "Deque elements after deleting front: ";
    dq.print();

    return 0;
}
