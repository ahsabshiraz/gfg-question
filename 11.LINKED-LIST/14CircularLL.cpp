// Implementation of a singly circular link-list and printing
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)//for loop
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    for (Node *p = head->next; p != head; p = p->next)
        cout << p->data << " ";
}

void printlist(Node *head)// do while loop
{
    if (head == NULL)
        return;
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(15);
    head->next->next->next = head;
    return 0;
}
