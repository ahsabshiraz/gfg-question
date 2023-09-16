// Delete the first Node in singly linked-list
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
void printlist(Node *head) // iterative
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteFirst(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *curr = head;
        head = head->next;
        delete curr;
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head = deleteFirst(head);
    printlist(head);
    return 0;
}