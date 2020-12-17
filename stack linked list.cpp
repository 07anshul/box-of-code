#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
};

class stackclass
{
    int input, popped_data, mode, total =0;
    node* top = nullptr;
    node* initial = top;
public:
    void edit();
    int push();
    int pop();
    int stack_top();
    int isempty()
    {
        return !top;
    }
    void print();
};

void stackclass::edit()
{
    cout << "EDIT THE STACK \n\t1. PUSH \n\t2. POP \n\t3. STACK TOP \n\t4. PRINT \n\t5. END EDIT";
    do
    {
        cout << "\n\nENTER MODE : ";
        cin >> mode;
        switch(mode)
        {
        case 1:
            push();
            break;
        case 2:
            cout << pop();
            break;
        case 3:
            cout << stack_top();
            break;
        case 4:
            print();
            break;
        case 5:
            cout << "\n\tSTACK IS EDITED SUCCESFULLY.\n";
            break;
        default:
            cout << "\n\tINVALID MODE.\n";
        }
    }
    while(mode != 5);
}

int stackclass::push()
{
    cout << "\nENTER DATA : ";
    cin >> input;

    node* block = new node();
    block -> data = input;
    block -> next = top;
    top = block;
    total++;
    return block -> data;
}

int stackclass::pop()
{
    if(isempty())
    {
        cout << "\n\tSTACK IS EMPTY.";
        return 0;
    }

    node* popped = top;
    top = top -> next;
    popped_data = popped -> data;
    total--;
    delete popped;

    return popped_data;
}

int stackclass::stack_top()
{
    if(isempty())
    {
        cout << "\n\tSTACK IS EMPTY.";
        return 0;
    }
    int top_element = top -> data;
    return top_element;
}

void stackclass::print()
{
    initial = top;
  for(int i = 0; i < total; i++)
  {
      cout << initial -> data << " ";
      initial = initial -> next;
  }
}
int main()
{
    stackclass s1;
    s1.edit();
}
