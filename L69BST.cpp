#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data)
  { // constructor
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

TreeNode *insertIntoBST(TreeNode *&root, int data)
{
  // base case
  if (root == NULL)
  {
    root = new TreeNode(data);
    return root;
  }

  if (data > root->data)
    root->right = insertIntoBST(root->right, data);
  else
    root->left = insertIntoBST(root->left, data);

  return root;
}

void takeInput(TreeNode *&root)
{
  int data;
  cin >> data;

  while (data != -1)
  {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

// breadth-first search algorithm
void BFS(TreeNode *root)
{
  queue<TreeNode*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    TreeNode *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      // purana level complete traverse ho chuka hai
      cout << endl;
      if (!q.empty())
      {
        // queue still has some child ndoes
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }

      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}

int main()
{

  TreeNode *root = NULL;
  cout << "Enter data to create BST: " << endl;
  takeInput(root);
  BFS(root);

  return 0;
}