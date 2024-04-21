//Major Task: The task is to complete the function remove Duplicates() which takes the head of
//input linked list as input. The function should remove the duplicates from linked list and return
//the head of the linked list.

//Major Task: The task is to complete the function getNthFromLast() which takes two arguments:
//reference to head and N and you need to return Nth from the end or -1 in case node doesn't
//exist. Note: Try to solve in a single traversal

#include <iostream>
#include <vector>
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

void print(Node* head){
    Node * temp = head;
    while (temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node * removeDuplicates(Node * head){
    vector <int> checklist;
    Node * curr = head;
    Node * prev = nullptr;
    while (curr!= nullptr){
        int foundFlag = 0;
        for (int i = 0 ; i <checklist.size() ; ++i){ //finding if elem exists already
            if (checklist[i] == curr->data){
                foundFlag = 1;
                break;
            }
            else{continue;}
        }
        if (!foundFlag){
            std::cout << curr->data << " -> " ; // printing if !exists
            checklist.push_back(curr->data);
            prev = curr;
        }
        else{ // delete if doesnt !exist
            prev->next = curr->next;
            delete curr;
            curr = prev;
        }
        curr = curr ->next;
    }
    return head;
}

int getNthFromLast(Node * head, int N){
    if (head == nullptr || N < 0){
        return -1;
    }
    Node * fast = head;
    Node * slow = head;
    for (int i = 0; i < N ; ++i){
        if (fast == nullptr){ // this maintains an N node gap between the 2 pointers
            return -1;
        }
        fast = fast->next;
    } 
    while (fast !=nullptr){
        fast = fast -> next;
        slow = slow-> next;
    }
    return slow->data;
}

int main(void){
    Node * head = NULL;
    Node * tail = NULL;
    insertAtEnd(head, 2);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    //print(head);
    removeDuplicates(head);
    cout<<endl;
    cout<< "slow data : " << getNthFromLast(head, 2) << endl;
    return 0;
}