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
    friend class Queue;
    friend class Stack;
public:
    Node* head;
    Node* tail;
    int Size;

    Deque() {
        head = tail = nullptr;
        Size = 0;
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

    void insertAtIndex(int data,int index) {
        Node* newnode = new Node(data);
        Node * curr = head;
        if (curr == nullptr) {
            curr = tail = newnode;
        } else {
            for (int i = 0 ; i<index ; i++){
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
        }
        Size++;
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

    void deleteRear() {
        if (tail == nullptr) {
            cout << "Underflow" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        Size--;
    }

    int getFront() {
        if (head == nullptr) {
            cout << "Deque is empty" << endl;
            return -1; // Return some default value
        }
        return head->data;
    }

    int getRear() {
        if (tail == nullptr) {
            cout << "Deque is empty" << endl;
            return -1; // Return some default value
        }
        return tail->data;
    }

    int size() {
        return Size;
    }

    bool isEmpty() {
        return Size == 0;
    }

    void erase() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        Size = 0;
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

class Queue {private: 
    Deque deque; 
    public: 
        void enqueue(int element); 
        int peek(); 
        void dequeue(); 
        int size(); 
}; 
void Queue::enqueue(int element) { return deque.insertRear(element); } 
int Queue::peek() { return deque.getFront(); } 
void Queue::dequeue() { deque.deleteFront(); } 
int Queue::size() { return deque.size(); }

class Stack {
private:
    Deque deque;
public:
    void push(int data) { deque.insertRear(data); }
    int top() { return deque.getRear(); }
    void pop() { deque.deleteRear(); }
    int size() { return deque.size(); } // Adding the size method
};


    // dq.insertRear(1);
    // dq.insertRear(2);
    // dq.insertRear(3);
    // dq.insertRear(4);
    // dq.insertRear(5);
    // cout << "Deque elements: ";
    // dq.print();
    // cout << "Front element: " << dq.getFront() << endl;
    // cout << "Rear element: " << dq.getRear() << endl;
    // dq.deleteFront();
    // cout << "Deque elements after removing front: ";
    // dq.print();
    // dq.deleteRear();
    // cout << "Deque elements after removing rear: ";
    // dq.print();
    // cout << "New front element: " << dq.getFront() << endl;
    // cout << "New rear element: " << dq.getRear() << endl;
    // dq.insertFront(6);
    // dq.insertFront(7);
    // cout << "Deque elements after adding 2 elements in the front: ";
    // dq.print();
    // dq.deleteRear();
    // cout << "Deque elements after removing one element from the back: ";
    // dq.print();
    // cout << "New front element: " << dq.getFront() << endl;
    // cout << "New rear element: " << dq.getRear() << endl;
    // while (!dq.isEmpty()) {
    //     dq.deleteFront();
    // }
    // cout << "Deque elements after removing all elements from the front: ";
    // dq.print();
    // cout << "Is Deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;
int main() {
    // Testing Deque
    Deque dq;

    // Inserting elements at the rear
    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertRear(3);
    dq.insertRear(4);
    dq.insertRear(5);

    cout << "Deque elements after inserting at the rear: ";
    dq.print();

    // Inserting elements at the front
    dq.insertFront(6);
    dq.insertFront(7);

    cout << "Deque elements after inserting at the front: ";
    dq.print();

    // Inserting an element at index 2
    dq.insertAtIndex(8, 2);
    cout << "Deque elements after inserting at index 2: ";
    dq.print();

    // Deleting front and rear elements
    dq.deleteFront();
    dq.deleteRear();

    cout << "Deque elements after deleting front and rear elements: ";
    dq.print();

    // Getting front and rear elements
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    // Checking size and emptiness
    cout << "Deque size: " << dq.size() << endl;
    cout << "Is Deque empty? " << (dq.isEmpty() ? "Yes" : "No") << endl;

    // Clearing the deque
    dq.erase();
    cout << "Deque elements after clearing: ";
    dq.print();

    // Testing Stack
    Stack st;

    // Pushing elements onto the stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element of the stack: " << st.top() << endl;

    // Popping elements from the stack
    st.pop();
    cout << "Top element after popping: " << st.top() << endl;

    // Getting stack size
    cout << "Stack size: " << st.size() << endl;

    return 0;
}



