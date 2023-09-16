#include <iostream>
#include <vector>
#include <algorithm>
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

int getsize(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + getsize(root->left) + getsize(root->right));
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    cout << getsize(root);
    return 0;
}