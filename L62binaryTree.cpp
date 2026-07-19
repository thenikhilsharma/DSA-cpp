#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// creating a tree with user input
node* buildTree(node* root) {

    cout << "Enter the data: ";
    int data;
    cin >> data;
    if(data == -1) return NULL;

    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
    cout << endl;

}

// breadth-first search algorithm
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;

            if(!q.empty()) q.push(NULL); //queue still has some child nodes
        }
        else{
            cout << temp -> data << " ";

            if(temp ->left) q.push(temp ->left);
            if(temp ->right) q.push(temp ->right);
        }
    }

}

// Left Node Right
void inorder(node* root) {
    //base case
    if(!root) return;

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

// Node Left Right
void preorder(node* root) {
    //base case
    if(!root) return;

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

// Left Right Node
void postorder(node* root) {
    //base case
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

int main() {

    node* root = NULL;

    buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "level order tracersal is:  " << endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root); 
    */

    return 0;
}