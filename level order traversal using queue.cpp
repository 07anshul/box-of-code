#include<bits/stdc++.h>
using namespace std;
class tree
{
public:
  int data;
  tree *left, *right;
  tree(int data)
  {
    this->data = data;
    left = right = nullptr;
  }
};

void levelOrderTraversal(tree *head)
{
  queue<tree*> q;
  while(head != nullptr)
  {
    cout << head->data << " ";
    if(head->left != nullptr)
    q.push(head->left);
    if(head->right != nullptr)
    q.push(head->right);
    head = q.front();
    q.pop();
  }
}

int main()
{
  tree *root = nullptr;
  root = new tree(1);
  root->left = new tree(2);
  root->right = new tree(3);
  root->left->left = new tree(4);
  root->left->right = new tree(5);
  root->left->left->left = new tree(6);
  root->left->left->right = new tree(7);

  levelOrderTraversal(root);
}
