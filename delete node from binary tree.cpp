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

void print(tree *root) {
  if (root == nullptr) {
    return;
  }
  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

int min(tree *root) {
  int min_value;
  if (root->left == nullptr) {
    return (root->data);
  }
  else {
    min_value = min(root->left);
  }
  return min_value;
}

void delete_node(tree *(&root), int data) {
  if (root == nullptr) {
    return;
  }
  else if (root->data == data) {
    // Leaf Node
    if (root->left == nullptr && root->right == nullptr) {
      delete(root);
      root = nullptr;
      return;
    }
    // One Child
    else if (root->left == nullptr) {
      delete(root);
      root = root->right;
      return;
    }
    else if (root->right == nullptr) {
      delete(root);
      root = root->left;
      return;
    }
    // Two Child
    else {
      int min_value = min(root->right);
      root->data = min_value;
      delete_node(root->right, min_value);
    }
  }
  else {
    delete_node(root->left, data);
    delete_node(root->right, data);
  }
}

int main() {
  tree *root = nullptr;
  root = new tree(30);
  root->left = new tree(14);
  root->right = new tree(32);
  root->left->left = new tree(13);
  root->left->right = new tree(16);
  root->right->left = new tree(31);
  root->right->right = new tree(35);
  root->left->right->left = new tree(15);
  root->left->right->right = new tree(18);
  root->right->right->left = new tree(34);
  root->right->right->right = new tree(40);
  root->left->right->right->left = new tree(17);
  root->left->right->right->right = new tree(22);

  delete_node(root, 16);
  print(root);
  cout << "\n";
}
