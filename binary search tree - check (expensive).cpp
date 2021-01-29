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

bool leftsubtree(tree* root, int value) {
  if (root == nullptr) {
    return true;
  }
  if (root->data <= value
       && leftsubtree(root->left, value)
      && leftsubtree(root->right, value)) {
    return true;
  }
  else {
    return false;
  }
}

bool rightsubtree(tree* root, int value) {
  if (root == nullptr) {
    return true;
  }
  if (root->data > value
      && rightsubtree(root->left, value)
      && rightsubtree(root->right, value)) {
    return true;
  }
  else {
    return false;
  }
}

bool check(tree *root) {
  if (root == nullptr) {
    return true;
  }
  if (leftsubtree(root->left, root->data)
      && rightsubtree(root->right, root->data)
      && check(root->left) && check(root->right)) {
        return true;
  }
  else {
    return false;
  }
}

int main() {
  tree *root = nullptr;
  root =  new tree(20);
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


  if (check(root)) {
    cout << "yes\n";
  }
  else {
    cout << "no\n";
  }
}
