#include<bits/stdc++.h>
using namespace std;
class tree {
public:
  int data;
  tree *left, *right;
  tree(int data) {
    this->data = data;
    left = right = nullptr;
  }
};
tree* insert(tree *root, int data) {
  if (root == nullptr) {
    root = new tree(data);
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return (root);
}

void print(tree *root) {
  queue<tree*> q;
  while(root != nullptr) {
    cout << root->data << " ";
    if (root->left != nullptr) {
      q.push(root->left);
    }
    if (root->right != nullptr) {
      q.push(root->right);
    }
    root = q.front();
    q.pop();
  }
}

int main() {
  tree *root = nullptr;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 8);
  root = insert(root, 20);
  root = insert(root, 13);
  root = insert(root, 23);

  print(root);
}
