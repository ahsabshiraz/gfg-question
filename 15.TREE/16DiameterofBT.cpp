// Diameter of the binary tree
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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}
int diameter(Node *root) // naive
{
    if (root == NULL)
        return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);
    return (max(d1, max(d2, d3)));
}
//--------------------------------------------
int res = 0;
int Diameter2(Node *root) // efficient
{
    if (root == NULL)
        return 0;
    else
    {
        int lh = Diameter2(root->left);
        int rh = Diameter2(root->right);
        res = max((1 + lh + rh), res);
        return (1 + max(lh, rh)); // this returns hieght of the tree ans sets res as diameter
    }
}

int main()
{

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->left->left = new Node(50);
    root->right->right->right = new Node(70);

    cout << diameter(root) << "\n";
    Diameter2(root);
    cout<<res;
}