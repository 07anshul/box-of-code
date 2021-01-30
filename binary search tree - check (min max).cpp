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

bool check(tree *root, int min, int max) {
  if (root == nullptr) {
    return true;
  }
  if (root->data > min && root->data <= max
       && check(root->left, min, root->data)
       && check(root->right, root->data, max)) {
         return true;
  }
  else {
    return false;
  }
}

bool final(tree *root) {
  return check(root, INT_MIN, INT_MAX);
}

int main() {
  tree *root = nullptr;
  root = new tree(20);
  root->left = new tree(17);
  root->right = new tree(30);
  root->left->left = new tree(17);
  root->left->right = new tree(18);
  root->right->left = new tree(25);
  root->right->right = new tree(37);
  root->left->left->left = new tree(10);
  root->left->right->left = new tree(18);
  root->left->right->right = new tree(19);
  root->right->left->right = new tree(29);
  root->right->right->right = new tree(43);

  if (final(root)) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
  }
}
