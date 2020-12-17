#include<bits/stdc++.h>
using namespace std;

class circular_queue
{
    int data, mode, front = -1, rear = -1, a[5];
    int length = (sizeof(a)/sizeof(a[0]));
public:
    void edit();
    void enqueue();
    void dequeue();
    void print();
};

void circular_queue::edit()
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

void circular_queue::enqueue()
{
    if((rear+1)%length == front)
    {
         cout << "\n\tQUEUE IS FULL.";
        return;
    }
    cout << "\nENTER DATA : ";
    cin >> data;
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        a[rear] = data;
    }
    else
    {
        ++rear;
        rear = rear%length;
        a[rear] = data;
    }
}

void circular_queue::dequeue()
{
    if(rear == -1 && front == -1)
    {
         cout << "\n\tQUEUE IS EMPTY.";
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        ++front;
        front = front%length;
    }
}

void circular_queue::print()
{
    int i;
    for(i = front; i != rear; i = (i+1)%length)
    {
        cout << a[i] << " ";
    }
    cout << a[i];
}

int main()
{
    circular_queue c1;

    c1.edit();
}
