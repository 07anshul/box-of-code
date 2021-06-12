#include<bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node* left;
  node* right;
};

int max(int arr[], int start, int end) {
  int max = start;
  for (int i = start+1; i < end; i++) {
    if (arr[i] > arr[max]) {
      max = i;
    }
  }

  return max;
}

node* newnode(int data) {
  node* TreeNode = new node();
  TreeNode->data = data;
  TreeNode->left = TreeNode->right = nullptr;

  return TreeNode;
}

node* tree(int arr[], int start, int end) {

  if (start > end) {
    return nullptr;
  }

  int maxindex = max(arr, start, end);

  node* root = newnode(arr[maxindex]);

  if (start == end) {
    return root;
  }

  root->left = tree(arr, start, maxindex-1);
  root->right = tree(arr, maxindex+1, end);

  return root;
}

void print(node* root) {
  if (root == nullptr) {
    return;
  }

  print(root->left);
  cout << root->data << " ";
  print(root->right);
}

int main() {
  int arr[] = {1, 5, 10, 40, 30, 15, 28, 20};

  int len = sizeof(arr)/sizeof(arr[0]);

  node* root = tree(arr, 0, len-1);

  print(root);
  cout << "\n";

}
