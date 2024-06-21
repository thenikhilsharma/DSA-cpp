#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }
};

void print(Node* &head){

    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

void len(Node* &head){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp -> next;
        cnt++;
    }
    cout << cnt;
}

void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){

    // inserting at first position
    if (pos == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp -> next;
        cnt++;
    }

    // inserting at last
    if (temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

// to study deletion of doubly linked list
void deleteNode(Node* &head, int pos){
    return;
}

int main(){

    cout << "doubly linked list" << endl;

    Node* node1 = new Node(10);     // new node creation
    Node* head = node1;
    Node* tail = node1;

    // cout << "Node 1 data " << node1->data << endl;

    insertAtPosition(head, tail, 18, 2);
    print(head);
    insertAtPosition(head, tail, 20, 2);
    print(head);
    insertAtPosition(head, tail, 30, 2);
    print(head);

    // cout << "Head " << head->data << endl;
    // cout << "Tail " << tail->data << endl;

    return 0;
}