#include<bits/stdc++.h>
using namespace std;

bool status = false;
class tree {
public:
  int data;
  tree *left, *right;

  tree(int data) {
    this->data = data;
    left = right = nullptr;
  }
};

void min(tree *root) {
  if (root->left == nullptr) {
    cout << root->data;
    return;
  }
  else {
    min(root->left);
  }
}

void successor(tree *root, int data) {
  if (root == nullptr) {
    return;
  }
  successor(root->left, data);
  if (root->data == data && root->right != nullptr) {
    min(root->right);
  }
  else if (root->data == data) {
    status = true;
    return;
  }
  if (status == true) {
    cout << root->data;
    status = false;
    return;
  }
  successor(root->right, data);
}

int main() {
  tree *root = nullptr;
  root = new tree(30);
  root->left = new tree(25);
  root->left->left = new tree(17);
  root->left->right = new tree(28);
  root->left->left->left = new tree(11);
  root->left->left->right = new tree(18);
  root->right = new tree(40);
  root->right->left = new tree(37);
  root->right->right = new tree(45);
  root->right->right->left = new tree(42);
  root->right->right->right = new tree(60);
  root->right->right->right->left = new tree(55);
  root->right->right->right->right = new tree(65);

  cout << "\n";
  successor(root, 42);
  cout << "\n";
  successor(root, 28);
  cout << "\n";
  successor(root, 25);
  cout << "\n";
  successor(root, 17);
  cout << "\n";
  successor(root, 45);
  cout << "\n";
  successor(root, 30);
}
