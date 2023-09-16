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

bool Rsearch(Node *root, int x)// recursive
{
    if (root == NULL)
        return false;
    if (root->key == x)
        return true;
    else if (root->key > x)
        return Rsearch(root->left, x);
    else
        return Rsearch(root->right, x);
}

bool search(Node *root, int x)//iterative
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        else if (root->key < x)
            root = root->right;
        else
            root = root->left;
    }
    return false;
}

int main()
{

    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int x = 15;

    if (Rsearch(root, x))
        cout << "Found";
    else
        cout << "Not Found";
}