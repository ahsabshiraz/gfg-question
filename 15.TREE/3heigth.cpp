// Height of a binary tree
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

int heigth(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return max(heigth(root->left), heigth(root->right)) + 1;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    cout << heigth(root);
    return 0;
}