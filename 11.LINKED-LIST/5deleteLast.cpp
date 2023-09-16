// Delete at last in singly link list
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

Node *deleteLast(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != NULL)//second last node
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = NULL;
        return head;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head = deleteLast(head);
    printlist(head);
    return 0;
}