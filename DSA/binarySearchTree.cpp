#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Helper: Insert a node recursively
    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);

        return node;
    }

    // Helper: Search for a value
    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        else return search(node->right, value);
    }

    // Helper: Find minimum value node (used in deletion)
    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    // Helper: Delete a node recursively
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) node->left = deleteNode(node->left, value);
        else if (value > node->data) node->right = deleteNode(node->right, value);
        else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: get inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Traversals
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() { root = nullptr; }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert nodes
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    cout << "Inserting values: ";
    for (int v : values) {
        cout << v << " ";
        tree.insert(v);
    }
    cout << "\n\n";

    // Display traversals
    cout << "Inorder traversal (sorted order): ";
    tree.inorder();

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    // Search demonstration
    cout << "\nSearching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Deletion demonstration
    cout << "\nDeleting 20 (leaf node)..." << endl;
    tree.remove(20);
    cout << "Inorder after deleting 20: ";
    tree.inorder();

    cout << "\nDeleting 30 (node with one child)..." << endl;
    tree.remove(30);
    cout << "Inorder after deleting 30: ";
    tree.inorder();

    cout << "\nDeleting 50 (root, node with two children)..." << endl;
    tree.remove(50);
    cout << "Inorder after deleting 50: ";
    tree.inorder();

    return 0;
}