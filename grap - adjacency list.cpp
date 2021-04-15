#include<bits/stdc++.h>
using namespace std;

class tree {
public:
  int friends;
  tree *left, *right;

  tree(int friends) {
    this->friends = friends;
    left = right = nullptr;
  }
};

tree* insert(tree* root, int data) {
  if (root == nullptr) {
    root = new tree(data);
  }
  else if (data < root->friends) {
    root->left = insert(root->left, data);
  }
  else if (data > root->friends) {
    root->right = insert(root->right, data);
  }
  return root;
}

void print(tree *root) {
  if (root == nullptr) {
    return;
  }
  print(root->left);
  cout << root->friends << " ";
  print(root->right);
}

int main() {

  tree* connections[10] = {nullptr};
  connections[1] = insert(connections[1], 2);
  connections[1] = insert(connections[1], 4);
  connections[1] = insert(connections[1], 5);

  connections[2] = insert(connections[2], 1);
  connections[2] = insert(connections[2], 3);
  connections[2] = insert(connections[2], 5);

  cout << "Friends of 1 are: ";
  print(connections[1]);
  cout << "\nFriends of 2 are: ";
  print(connections[2]);

}
