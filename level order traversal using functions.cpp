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

int height(tree *head);
void printGivenLevel();
void printLevelOrder();

int height(tree *head)
{
  if(head == nullptr)
  return 0;
  else
  {
    int heightOfLeftTree = height(head->left);
    int heightOfRightTree = height(head->right);

    if(heightOfLeftTree > heightOfRightTree)
    return (heightOfLeftTree +1);
    else
    return (heightOfRightTree +1);
  }
}

void printGivenLevel(tree *head, int level)
{
  if(head == nullptr)
  return;
  else if(level == 1)
  cout << head->data << " ";
  else if(level > 1)
  {
    printGivenLevel(head->left, level-1);
    printGivenLevel(head->right, level-1);
  }
}

void printLevelOrder(tree *head)
{
  int h = height(head);
  for(int i = 1; i <= h; i++)
  printGivenLevel(head, i);
}

int main()
{
  tree *root = nullptr;
  root = new tree(1);
  root->left = new tree(2);
  root->right = new tree(3);
  root->left->left = new tree(4);
  root->left->right = new tree(5);
  root->left->left->left = new tree(6);

  printLevelOrder(root);
}
