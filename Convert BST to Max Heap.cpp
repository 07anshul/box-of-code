#include<bits/stdc++.h>
using namespace std;

int i = 0;

class tree {
public:
  int data;
  tree* left;
  tree* right;

  tree(int data) {
    this->data = data;
    left = right = nullptr;
  }
};


vector<int> inorder(tree* root, vector<int> sorted) {
  if (root == nullptr) {
    return sorted;
  }

  sorted = inorder(root->left, sorted);
  sorted.push_back(root->data);
  sorted = inorder(root->right, sorted);

  return sorted;
}

void postorder(tree* root, vector<int> &sorted) {
  if (root == nullptr) {
    return;
  }

  postorder(root->left, sorted);
  postorder(root->right, sorted);
  root->data = sorted[i];
  ++i;
}

void print(tree* root) {
  if (root == nullptr) {
    return;
  }

  print(root->left);
  print(root->right);
  cout << root->data << " ";
}

int main() {
  tree* root = new tree(25);
  root->left = new tree(15);
  root->right = new tree(50);
  root->left->left = new tree(10);
  root->left->right = new tree(22);
  root->right->left = new tree(35);
  root->right->right = new tree(70);

  vector<int> sorted;

  sorted = inorder(root, sorted);

  postorder(root, sorted);

  print(root);
}
