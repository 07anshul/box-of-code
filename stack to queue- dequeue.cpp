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
    s1.push(data);
}

int queueclass::dequeue()
{
    if(s1.empty() && s2.empty())
    {
        cout << "\n\tQUEUE IS EMPTY.";
        return 0;
    }

    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int front = s2.top();
    s2.pop();

    return front;

}
int main()
{
    queueclass q1;

    q1.enqueue(21);
    q1.enqueue(12);
    q1.enqueue(123);
    q1.enqueue(143);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(111);
    q1.enqueue(232);
    q1.enqueue(90);

    cout << q1.dequeue() << " ";
    cout << q1.dequeue() << " ";

    q1.enqueue(121);
    q1.enqueue(51);

    cout << q1.dequeue() << " ";
}
