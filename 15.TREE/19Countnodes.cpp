// count node in a complete binary tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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

int Countnode(Node *root) // naive
{
    if (root == NULL)
        return 0;
    else
        return 1 + Countnode(root->left) + Countnode(root->right);
}

int countnodes(Node *root)//efficient
{
    Node *curr = root;
    int lh = 0, rh = 0;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
        return pow(2, lh) - 1;
    else
        return 1 + countnodes(root->left) + countnodes(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    return 0;
}