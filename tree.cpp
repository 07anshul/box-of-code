#include<bits/stdc++.h>
using namespace std;
class tree
{
public:
  int data;
  tree* left;
  tree* right;
  
  tree(int);
};
tree::tree(int x)
{
  data = x;
  left = right = nullptr;
}
void inorder(tree* head)
{
  stack<tree*> s;
  while(head!= nullptr || !s.empty())
    {
      while(head != nullptr)
	{
	  s.push(head);
	  head = head->left;
	}
      head = s.top();
      s.pop();
      cout << head->data << " ";
      head = head->right;
    }
}
int main()
{
  tree* root = new tree(4);
  root->left = new tree(5);
  root->right = new tree(43);
  root->left->left = new tree(54);
  root->left->right = new tree(21);
  root->right->left = new tree(121);

  inorder(root);
}
