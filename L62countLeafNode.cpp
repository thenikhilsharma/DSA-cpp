#include<iostream>
#include<queue>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void buildLOT(node* &root){
    queue<node*> q;

    int data, leafNode;
    cin >> data;
    root = new node(data);

    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftData;
        cin >> leftData;
        if (leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inorder(node* root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
    if (root-> left == NULL && root->right == NULL){
        count++;
    }
    inorder(root->right, count);

}

int noOfLeafNode(node* root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main(){
    node* root = NULL;
    buildLOT(root);

    cout << "No of leaf nodes are: " << noOfLeafNode(root) << endl;
    return 0;
}