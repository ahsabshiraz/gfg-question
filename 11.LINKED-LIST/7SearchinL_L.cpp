// Search in a linked-list(iterative and recursive)
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
int Search(Node *head, int x) // iterative
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
            return pos;
        else
        {
            curr = curr->next;
            pos++;
        }
    }
    return -1;
}

int Rsearch(Node *head, int x)
{
    if (head == NULL)
        return -1;
    if (head->data == x)
        return 1;
    else
    {
        int res = Rsearch(head->next, x);
        if (res == -1)
            return -1;
        else
            return (res + 1);
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(20);
    head->next->next->next = new Node(25);
    int pos = Search(head, 25);
    int pos1 = Rsearch(head, 15);
    cout << pos << " " << pos1 << endl;
    printlist(head);

    return 0;
}