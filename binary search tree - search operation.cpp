#include<bits/stdc++.h>
using namespace std;
class tree
{
public:
  int data;
  tree *left , *right;
  tree(int data)
  {
    this->data = data;
    left = right = nullptr;
  }
};

void search(tree *head, int data)
{
  while(head != nullptr) {
    if(data == head->data) {
      cout << "Data is present!";
      return;
    } else if(data < head->data) {
      head = head->left;
    } else {
      head = head->right;
    }
  }
  cout << "Data is not present!";
}
int main()
{
  tree *root = nullptr;
  root = new tree(15);
  root->left = new tree(10);
  root->right = new tree(19);
  root->left->left = new tree(8);
  root->left->right = new tree(12);
  root->right->left = new tree(17);
  root->right->right = new tree(21);

int data;
  cout << "Enter the data to search : ";
  cin >> data;
  search(root, data);
}
