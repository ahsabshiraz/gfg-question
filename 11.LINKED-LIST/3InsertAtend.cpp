// Insert at the end of the Link list

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

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        // head = temp;
        return temp;
    }

    else
    {
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
        return head;
    }
}

int main()
{
    Node *head = NULL; //= new Node(10);
    head = insertEnd(head, 15);
    head = insertEnd(head, 20);
    printlist(head);

    return 0;
}
