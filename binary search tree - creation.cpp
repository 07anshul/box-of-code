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
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return (root);
}

// void print(tree *root) {
//   queue<tree*> q;
//   while(root != nullptr) {
//     cout << root->data << " ";
//     if (root->left != nullptr) {
//       q.push(root->left);
//     }
//     if (root->right != nullptr) {
//       q.push(root->right);
//     }
//     root = q.front();
//     q.pop();
//   }
// }

void print(tree *root) {
  if (root == nullptr) {
    return;
  }

  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

int countTree(tree *root)
{

if(root==NULL) {
  return 0;
} //base case
else {
  if (root->left != NULL && root->left->data==root->data) {
    return 1+countTree(root->left)+countTree(root->right);
  }
  else {
    return countTree(root->left)+countTree(root->right);
  }
}


}

// 3 3 4 2 4 5 6 2

int main() {
  tree *root = nullptr;
  root = insert(root, 3);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 2);

  print(root);
  cout << countTree(root);
}
