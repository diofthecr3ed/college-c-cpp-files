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

    void insertRear(int data) {
        Node* newnode = new Node(data);
        if (tail == nullptr) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        Size++;
    }

    int size() {
        return Size;
    }

    bool isEmpty() {
        return Size == 0;
    }


    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node * sortedInsert(int n){
        Node* newnode = new Node(n);
        Node * curr = head;
        Node * prev = nullptr;
        if (head == nullptr) {
            head = newnode;
        } else{
            while (curr != nullptr){
                if (curr->data > newnode->data){
                    newnode->next = curr;
                    prev->next = newnode;
                    break;
                }
                else{
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
}
};



int main() {
    Deque dq;
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertRear(3);
    dq.insertRear(5);
    dq.insertRear(7);
    dq.print();
    dq.sortedInsert(6);
    dq.print();

    return 0;
}



