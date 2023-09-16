// Reverse a L-L (iterative)
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
Node *revList(Node *head) // two traversal solution
{
    vector<int> arr;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }

    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        curr->data = arr.back();
        arr.pop_back();
    }
    return head;
}

Node *revList1(Node *head)
{
    Node *curr = head, *prev = NULL;
    while(curr!=NULL)
    {
        Node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main()
{ 
    return 0;
}