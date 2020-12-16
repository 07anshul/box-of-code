#include<bits/stdc++.h>
using namespace std;
class tree
{
public:
  int data;
  tree *left, *right;
  tree(int data)
  {
    this->data = data;
    left = right = nullptr;
  }
};
int height(tree* head)
{
  if(head == nullptr)
  return 0;
  else
  {
    int height_of_left_side = height(head->left);
    int height_of_right_side = height(head->right);

    if(height_of_left_side > height_of_right_side)
    return (height_of_left_side +1);
    else
    return (height_of_right_side +1);
  }
}
int main()
{
  tree* root = nullptr;
  root = new tree(1);
  root->left  = new tree(2);
  root->right = new tree(3);
  root->left->left = new tree(4);
  root->left->right = new tree(5);

  cout << height(root);
}
