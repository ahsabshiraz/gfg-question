// Simple implementation of link-list and traversing singly l-l
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int x;
    Node *next;
    Node(int y)
    {
        x = y;
        next = NULL;
    }                 
};   

void printlist(Node *head) // iterative
{
    while (head != NULL)
    {
        cout << head->x << " ";
        head = head->next;
    }
}

void Rprintlist(Node *head) // recursive
{
    if (head == NULL)
        return;
    cout << head->x << " ";
    Rprintlist(head->next);
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    cout << endl;
    Rprintlist(head);
    return 0;
}