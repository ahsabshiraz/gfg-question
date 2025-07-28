#include <bits/stdc++.h>
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

void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *pairwiseSwap(Node *head) // Method 2(Changing Pointers/References)
{
    if (head == NULL || head->next == NULL)
        return head;
    // do the first pass manually  bcz we are dealing with head here
    Node *curr = head->next->next;// secure the the next pass first element
    Node *prev = head;// secure the  first 
    head = head->next;
    head->next = prev;//make second element point at first
    while (curr != NULL && curr->next != NULL) // 1,2,3,4,5 //2,1,4,3,5
    {
        prev->next = curr->next;// make the  first point at next passes second element
        prev = curr;//make the prev point at next passes curr head
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    } 
    prev->next = curr;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    printlist(head);
    head = pairwiseSwap(head);
    printlist(head);
    return 0;
}
