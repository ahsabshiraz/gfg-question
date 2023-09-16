#include <bits/stdc++.h>
#include <queue>
using namespace std;

void Print(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reverse(queue<int> &q) // recursive
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();

    reverse(q);
    q.push(x);
}
void reverseQueue(queue<int> &Queue)//iterative
{
    stack<int> Stack;
    while (!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    reverse(q);
    Print(q);
}
