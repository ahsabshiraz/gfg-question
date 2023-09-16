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

Node *sortedinsert(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    if (x < head->x)
    {
        temp->next = head;
        return temp;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL && curr->next->x < x)
        {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        return head;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(35);
    head->next->next->next->next = new Node(45);
    head = sortedinsert(head, 40);
    printlist(head);
    return 0;
}
