#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

    // constructor
    Node (int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertData(Node* &tail, int element, int data){
    if (tail == NULL){
        Node* node1 = new Node(data);
        tail = node1;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> next = tail->next;
        tail = temp;
    }
}

void print(Node* &tail){
    Node* itr = tail->next;
    while (itr != tail){
        cout << itr->data << " ";
        itr = itr->next;
    }
    cout << tail->data << endl;
}

int main(){

    Node* node1 = new Node(12);
    Node* tail = node1;
    insertData(tail, 1, 15);
    insertData(tail, 1, 20);
    insertData(tail, 1, 30);
    insertData(tail, 1, 40);

    print(tail);
    return 0;
}