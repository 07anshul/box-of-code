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

int  min(tree *root) {
  int minimum;
  if (root == nullptr) {
    cout << "TREE IS EMPTY!";
  } else if (root->left == nullptr) {
    return (root->data);
  } else {
   minimum = min(root->left);
  }
return (minimum);
}

int max(tree *root) {
  int maximum;
  if (root == nullptr) {
    cout << "TREE IS EMPTY!";
  }  else if (root->right == nullptr) {
    return (root->data);
  } else {
    maximum = max(root->right);
  }
  return (maximum);
}

int main() {
  tree *root = nullptr;
  root = insert(root, 15);
  root = insert(root, 43);
  root = insert(root, 11);
  root = insert(root, 12);
  root = insert(root, 76);
  root = insert(root, 3);
  root = insert(root, 112);
  root = insert(root, 6);

  cout << "minimum : " << min(root) << "\n";
  cout << "maximum : " << max(root);
}
