#include<bits/stdc++.h>
using namespace std;

class queueclass
{
    stack <int> s;
public:
    void enqueue(int data);
    int dequeue();
};

void queueclass::enqueue(int data)
{
    s.push(data);
}

int queueclass::dequeue()
{
    if(s.empty())
    {
        cout << "\n\tQUEUE IS EMPTY.";
        return 0;
    }

    int element = s.top();
    s.pop();

    if(s.empty())
        return element;

    int front = dequeue();

    s.push(element);

    return front;
}
int main()
{
    queueclass q1;

    q1.enqueue(22);
    q1.enqueue(242);
    q1.enqueue(213);
    q1.enqueue(325);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(3255);
    q1.enqueue(3632);
    q1.enqueue(54);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(313);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
}
