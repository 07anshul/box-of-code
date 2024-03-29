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
  root = new tree(1);
  root->left = new tree(1);

  if (final(root)) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
  }
}
