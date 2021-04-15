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

bool check(tree *root, int min) {
   if (root == nullptr) {
     return true;
   }
   check(root->left, min);
   if (root->data < min) {
     return false;
   }
   min = root->data;
   check(root->right, min);
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
  root->left->right->right = new tree(21);
  root->right->left->right = new tree(29);
  root->right->right->right = new tree(43);

  check(root, INT_MIN);
}
