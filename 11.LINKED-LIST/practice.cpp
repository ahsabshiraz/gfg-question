#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node *clone(Node *head)
{
    Node *curr = head;
    while (curr and curr->next)
    {
        Node *nxt = curr->next;
        Node *ptr = new Node(curr->data);
        curr->next = ptr;
        ptr->next = nxt;
        curr = nxt;
    }

    curr = head;
    while (curr and curr->next)
    {
        Node *clone = curr->next;
        clone->random = (curr->random) ? curr->random->next : NULL;
        curr = curr->next->next;
    }

    Node *Org = head, *clone = head->next;
    Node *temp = clone;
    while (Org and clone)
    {
        Org->next = (Org->next) ? Org->next->next : Org->next;
        clone->next = (clone->next) ? clone->next->next : clone->next;
        Org = Org->next;
        clone = clone->next;
    }
    return temp;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    cout << "Original list : \n";
    print(head);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);

    return 0;
}
