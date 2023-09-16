// tree traversal in spiral from
// Creating a binary tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        right = left = NULL;
    }
};

void printSpiral(Node *root)//method-1 (using queue and stack)
{
    if (root == NULL)
        return;
    else
    {
        queue<Node *> q;
        stack<int> s;
        q.push(root);
        bool reverse = false;
        while (q.empty() == false)
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (reverse)
                    s.push(curr->key);
                else
                    cout << curr->key << " ";
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            if (reverse)
            {
                while (s.empty() == false)
                {
                    cout << s.top() << " ";
                    s.pop();
                }
            }
            reverse = !reverse;
            cout << "\n";
        }
    }
}

void printSpiral2(Node *root)//method-2 (using two stacks)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->key << " ";

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->key << " ";

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(10);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    printSpiral(root);
}