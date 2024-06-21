#include<iostream>
using namespace std;

class Node {
    
    public:
        int data;
        Node *next;

        // constructor
        Node(int data) {
            this -> data = data;        // add data to the node
            this -> next = NULL;        // set next address of the node as NULL
        }

        // destructor
        ~Node() {
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
            // cout << "memory is free for data "<< value << endl;
        }
};

// insert at head
void InsertAtHead(Node* &head, int data){

    Node *temp = new Node(data);    // new node create
    temp -> next = head;            // link address of the head to the initial list
    head = temp;                    // set new data as the new head
}

// insert at tail
void InsertAtTail(Node* &tail, int data){

    Node *temp = new Node(data);    // new node create
    tail -> next = temp;            // new data at the end of the tail
    tail = temp;                    // set new data as the new tail
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int data){

    // insert at head
    if (position == 1){
        InsertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    if (temp -> next == NULL){
        InsertAtTail(tail, data);
        return;
    }

    Node *NodeToInsert = new Node(data);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
}

void deleteNode(int position, Node* & head, Node* &tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        if (curr -> next == NULL){
            prev -> next = curr -> next;
            tail = prev;
        }
        else{
            prev -> next = curr -> next;
        }
        curr -> next  = NULL;
        delete curr;

    }
}

// printing the linked list
void print(Node* &head) {
    Node *temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node *node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtHead(head, 15);
    print(head);

    InsertAtPosition(head, tail, 4, 300);
    print(head);

    deleteNode(2, head, tail);
    print(head);

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    return 0;
}