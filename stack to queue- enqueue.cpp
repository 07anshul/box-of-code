#include<bits/stdc++.h>
using namespace std;

class queueclass
{
    stack <int> s1, s2;
public:
    void enqueue(int data);
    int dequeue();
};

void queueclass::enqueue(int data)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(data);

    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

int queueclass::dequeue()
{
    if(s1.empty())
    {
        cout << "\n\tQUEUE IS EMPTY.";
        return 0;
    }
    int front = s1.top();
    s1.pop();

    return front;
}

int main()
{
    queueclass q1;

    q1.enqueue(121);
    q1.enqueue(3133);
    q1.enqueue(423);
    q1.enqueue(41);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(133);
    q1.enqueue(1341);
    q1.enqueue(42);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(234);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
}
