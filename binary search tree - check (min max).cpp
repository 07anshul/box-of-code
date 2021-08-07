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
  root = new tree(30);
  root->left = new tree(14);
  root->right = new tree(32);
  root->left->left = new tree(13);
  root->left->right = new tree(18);
  root->right->left = new tree(31);
  root->right->right = new tree(35);
  root->left->right->left = new tree(15);
  root->left->right->right = new tree(22);
  root->right->right->left = new tree(34);
  root->right->right->right = new tree(40);
  root->left->right->right->left = new tree(19);

  if (final(root)) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
  }
}
