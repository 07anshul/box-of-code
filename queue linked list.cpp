#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* next;
};

class queueclass
{
    int data, mode;
    node* front = nullptr;
    node* rear = nullptr;
    node* initial = front;
    node* block;
    node* run_block;
    node* node_delete;
public:
    void edit();
    void enqueue();
    void dequeue();
    int isempty()
    {
        return !front;
    }
    void print();
};

void queueclass::edit()
{
     cout << "EDIT THE STACK \n\t1. ENQUEUE \n\t2. DEQUEUE \n\t3. PRINT \n\t4. END EDIT";
    do
    {
        cout << "\n\nENTER MODE : ";
        cin >> mode;
        switch(mode)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        case 4:
            cout << "\n\tSTACK IS EDITED SUCCESFULLY.\n";
            break;
        default:
            cout << "\n\tINVALID MODE.\n";
        }
    }
    while(mode != 4);
}

void queueclass::enqueue()
{
    block = new node();
    run_block = front;

    if(front == nullptr && rear == nullptr)
    {
         cout << "\nENTER DATA : ";
        cin >> data;

        block -> data = data;
        block -> next = front;
        front = block;
        rear = block;
    }
    else
    {
         cout << "\nENTER DATA : ";
        cin >> data;

        block -> data = data;
        while(run_block -> next != nullptr)
            run_block = run_block -> next;
        run_block -> next = block;
        block -> next = nullptr;
        rear = block;
    }

}

void queueclass::dequeue()
{
    if(isempty())
    {
        cout << "\n\tQUEUE IS EMPTY.";
        rear = front;
        return;
    }
    node_delete = front;
    front = front -> next;
    delete node_delete;
}

void queueclass::print()
{
        initial = front;
        while(initial != nullptr)
        {
            cout << initial -> data << " ";
            initial = initial -> next;
        }
}


int main()
{
    queueclass q1;

    q1.edit();
}
