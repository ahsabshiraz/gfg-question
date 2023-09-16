#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};
void inorder(Node *root) // print
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

Node *insert(Node *root, int x) // recursive
{
    if (root == NULL)
        return new Node(x);
    if (root->key < x)
        root->right = insert(root->right, x);
    else if (root->key > x)
        root->left = insert(root->left, x);
    return root;
}
Node *insert1(Node *root, int x)// iterative
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
            curr = curr->left;
        else if (curr->key < x)
            curr = curr->right;
        else
            return root;
    }
    if (parent == NULL)
        return temp;
    if (parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}
int main()
{

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 20;

    root = insert(root, x);
    inorder(root);
}