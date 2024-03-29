#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int val): data(val){next = NULL;}
};

void insertAtEnd(Node * &head, int val){
    Node * n = new Node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    Node * temp = head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(Node * &head, int val){
    Node * n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtIndex(Node * head, int val, int index){
    Node * n = new Node(val);
    if (head == nullptr || index == 0){
        n->next = head;
        head = n; 
        return;
    }
    Node * temp = head;    
    for (int i = 1; i < index - 1 && temp->next != nullptr; ++i){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}


void print(Node* head){
    Node * temp = head;
    while (temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(Node * &head, int val){
    if (head ==NULL){return;}
    Node * temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    Node * popped = temp->next;
    temp->next = temp->next->next;
    delete popped;
}

int main(void){
    Node * head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtEnd(head, 1);
    insertAtHead(head, 2);
    insertAtIndex(head, 3, 3);
    print(head);
    deleteNode(head,1);
    print(head);
    return 0;
}