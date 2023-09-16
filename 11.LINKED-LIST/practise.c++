#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
          int data;
          Node *next, *prev;
          Node(int x)
          {
                    data = x;
                    next = prev = NULL;
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
int reverseK(Node *head, int k)
{
          Node *prevfirst = NULL, *curr = head;
          bool isfirstPass = true;
          while (curr != NULL)
          {
                    Node *first = curr, *prev = NULL;
                    int count = 0;
                    while (curr != NULL and count < k)
                    {
                              Node *next = curr->next;
                              curr->next = prev;
                              prev = curr;
                              curr = next;
                              count++;
                    }
                    if (isfirstPass)
                    {
                              head = prev;
                              isfirstPass = false;
                    }
                    else
                              prevfirst->next = prev;
                    prevfirst = first;
          }
          return head;
}

int main()
{
          Node *head = new Node(10);
          head->next = new Node(20);
          head->next->next = new Node(30);
          head->next->next->next = new Node(40);
          head->next->next->next->next = new Node(50);
          head->next->next->next->next->next = new Node(60);
          head->next->next->next->next->next->next = new Node(70);
          printlist(head);
          head = reverseK(head, 3);
          printlist(head);
          return 0;
}
