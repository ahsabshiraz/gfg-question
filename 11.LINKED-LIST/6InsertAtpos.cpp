// Insert at position in singly link list
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
Node *insertAtpos(Node *head, int x, int pos)
{
    Node *temp = new Node(x);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    else
    {
        Node *curr = head;
        for (int i = 0; i < pos - 2 && curr != NULL; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            return head;
        temp->next = curr->next;
        curr->next = temp;
        return head;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    head = insertAtpos(head, 45, 4);
    printlist(head);
    return 0;
}