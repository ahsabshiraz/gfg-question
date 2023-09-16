// Insert at the begining of the Link list

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

Node *insertAtbegin(Node *head, int x)//my code
{
    if (head == NULL)
    {
        head = new Node(x);
        return head;
    }

    else
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        return head;
    }
}


int main()
{
    Node *head ;//= new Node(10);
    head = insertAtbegin(head, 15);
    printlist(head);

    return 0;
}
